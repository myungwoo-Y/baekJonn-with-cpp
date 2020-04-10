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

map<VI, int> m;


void preCalc(int n){
    VI arr(n);
    for (int i = 0; i < arr.size(); ++i) arr[i] = i;
    queue<VI> q;
    m[arr] = 0;
    q.push(arr);

    while(!q.empty()){
        VI here = q.front();
        int cost = m[here];
        q.pop();
        for (int i = 0; i < n; ++i) {
            for (int j = i+2; j <= n; ++j) {
                reverse(here.begin()+i, here.begin()+j);
                if(m.count(here) == 0){
                    m[here] = cost+1;
                    q.push(here);
                }
                reverse(here.begin()+i, here.begin()+j);
            }
        }
    }
}

// 0...n-1 배열로 변환한다.
// 각 원소가 몇번째로 큰지 나타내는것과 같다.
int solve(const VI& arr){
    int n = arr.size();
    VI fixed(n);
    for (int i = 0; i < n; ++i) {
        int smaller = 0;
        for (int j = 0; j < n; ++j)
            if(arr[j] < arr[i])
                smaller++;
        fixed[i] = smaller;
    }
    return m[fixed];
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
        m = map<VI, int>();
        int n {};
        cin >> n;
        VI arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        preCalc(n);
        cout << solve(arr) << endL;
    }

    return 0;
}