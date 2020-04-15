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

struct RMQ {
    int n;

    vector<int>rangeMin;
    RMQ(const vector<int>& arr){
        n = arr.size();
        rangeMin.resize(n*4);
        init(arr, 0, n-1, 1);
    }
    int init(const vector<int>& arr, int left, int right, int node){
        if(left==right)
            return rangeMin[node] = arr[left];

        int mid = (left+right)/2;
        int leftMin = init(arr, left, mid, node*2);
        int rightMin = init(arr, mid+1, right, node*2+1);
        return rangeMin[node] = min(leftMin, rightMin);
    }

    int query(int left, int right, int node, int nodeLeft, int nodeRight){
        if(right < nodeLeft || left > nodeRight)
            return INT32_MAX;
        if(left <= nodeLeft && right <= nodeRight)
            return rangeMin[node];
        int mid = (nodeLeft+nodeRight)/2;
        return min(query(left, right, node*2, nodeLeft, mid),
                   query(left, right, node*2+1, mid+1, nodeRight));
    }
    int query(int left, int right){
        return query(left, right, 1, 0, n-1);

};


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #endif

    return 0;
}