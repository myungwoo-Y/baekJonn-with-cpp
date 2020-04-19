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
int n {}, trainN {};
VII dp;
VI arr;
VI sums;
int MIN = -100000000;

int findMax(int idx, int seq){
    if(seq == 3)
        return 0;

    if(idx >= n)
        return MIN;

    int& ret = dp[idx][seq];
    if(ret != -1)
        return ret;

    int rangeSum {};
    int remain {};
    if(idx > 0)
        remain = sums[idx - 1];
    if(idx + trainN - 1 >= n)
        return MIN;
    rangeSum = sums[idx + trainN - 1] - remain;

    ret = 0;
    ret = max(findMax(idx+1, seq), rangeSum+findMax(idx+trainN, seq+1));
    return ret;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;

    arr.resize(n);
    sums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sums[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        sums[i] = sums[i-1]+arr[i];
    }

    cin >> trainN;
    dp.resize(n, VI(3, -1));

    cout << findMax(0, 0);
    return 0;
}