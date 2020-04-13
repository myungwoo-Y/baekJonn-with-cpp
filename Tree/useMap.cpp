// 종만북 너드인가
// 이코드는 알고스팟에서 컴파일 불가
// Tree Map의 자료 구조를 이용하는 문제이다.
#include <bits/stdc++.h>
#define VII vector<vector<int>>
#define VDD vector<vector<double>>
#define VCC vector<vector<char>>
#define VSS vector<vector<string>>
#define VBB vector<vector<bool>>
#define VLL vector<vector<long long>>
#define VI vector<int>
#define VB vector<bool>
#define VS vector<string>
#define VC vector<char>
#define VD vector<double>
#define VL vector<long long>
#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>

using namespace std;
const string endL = "\n";

string s;

struct D{
    int l {}, p {};
};

map<int, int> m;

bool isDominated(int x, int y){
    map<int, int>::iterator it = m.lower_bound(x);

    if(it == m.end()) return false;

    return it->second > y;
}

void removeDominated(int x, int y){
    auto it = m.lower_bound(x);
    // 추가할려는 원소가 제일 처음인 경우
    if(it == m.begin()) return;
    it--;
    while(true){
        if(it->second > y) break;
        // 더이상 지울게 없는 경우
        if(it == m.begin()){
            m.erase(it);
            break;
        }else{
            // it을 이전으로 이동 후 삭제, 그리고 다시 할당
            auto jt = it;
            jt--;
            m.erase(it);
            it = jt;
        }
    }
}

int registered(int x, int y){
    if(isDominated(x, y)) return m.size();
    removeDominated(x, y);
    m[x] = y;
    return m.size();
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #endif

    int testCase {};
    cin >> testCase;

    loop(testCase){
        int n {};
        cin >> n;
        vector<D> arr;

        for (int i = 0; i < n; ++i) {
            int l, p;
            cin >> l >> p;
            arr.push_back({l, p});
        }

        int sum {};

        for (int i = 0; i < n; ++i) {
            D cur = arr[i];
            sum += registered(cur.p, cur.l);
        }
        cout << sum << endL;

    }

    return 0;
}