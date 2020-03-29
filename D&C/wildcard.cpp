#include <bits/stdc++.h>

#define VII vector<vector<int>>
#define VDD vector<vector<double>>
#define VCC vector<vector<char>>
#define VSS vector<vector<string>>
#define VI vector<int>
#define VB vector<bool>
#define VS vector<string>
#define VC vector<char>
#define VD vector<double>
#define SI string::iterator
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>
using namespace std;

const string endL {"\n"};

int n {};

VII dp;

string S, W;

bool match(int w, int s){
    int& ret = dp[w][s];
    if(dp[w][s] != -1) return ret;
    if(s < S.size() && w < W.size() &&
       (W[w] == '?' || W[w] == S[s])){
        return ret = match(w+1, s+1);
    }

    if(w == W.size()){
        return ret=(s==S.size());
    }

    if(W[w] == '*'){
        if(match(w+1, s) || (s <= S.size() && match(w, s+1)))
            return ret = 1;
    }
    return dp[w][s] = 0;
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
        string base;
        cin >> base >> n;

        VS strs(n);
        for (int i = 0; i < n; ++i) {
            cin >> strs[i];
        }
        VS list;
        for (auto str : strs) {
            S = str;
            W = base;
            dp = VII(101, VI(101, -1));
            if(match(0, 0)){
                list.push_back(str);
            }
        }
        sort(list.begin(), list.end());
        for(auto item : list){
            cout << item << endL;
        }
    }

    return 0;
}