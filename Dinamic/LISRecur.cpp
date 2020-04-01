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
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>
using namespace std;

VI dp;
VI a;
VI b;

int aLen {}, bLen {};

int lis(int start){
    int& ret = dp[start];

    if(ret != -1) return ret;
    ret = 1;
    for (int i = start+1; i < aLen; ++i) {
        if(a[start] < a[i]){
            ret = max(ret, lis(i) + 1);
        }
    }
    return ret;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #endif

    cin >> aLen;

    a = VI(aLen);
    dp = VI(aLen, -1);

    for (int i = 0; i < aLen; ++i) {
        cin >> a[i];
    }

    cout << lis(0);


    return 0;
}