// 알고스팟 ITES

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

const string endL {"\n"};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #endif

    int testCase {};
    cin >> testCase;

    LL one {1};
    loop(testCase){
        LL k {}, n {};
        queue<LL> q;

        cin >> k >> n;
        LL sum {};
        int cnt {};
        LL record {1983};
        loop(n){
            LL signal = (record%10000) + 1;

            q.push(signal);
            sum += signal;

            while(sum > k){
                sum -= q.front();
                q.pop();
            }

            cnt += (sum == k);

            record = (record * 214013 + 2531011) % (one << 32);
        }
        cout << cnt << endL;
    }

    return 0;
}