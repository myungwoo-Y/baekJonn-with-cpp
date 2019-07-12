#include <iostream>
#include "ostream"
#include "algorithm"

using namespace std;

int combinateFile() {
    ios_base::sync_with_stdio(false);
    int n, k, y, t;
    //auto dp = new int[500][500];
    int dp[500][500];
    cin >> n;
    while (n--) {
        cin >> k;
        int sum[k];
        int temp;
        cin >> sum[0];
        for(int i = 1; i < k; i++){
            cin >> sum[i];
            sum[i] += sum[i-1];
        }

        for(int d = 1; d < k; d++){
            for(int x = 0; x+d < k; x++){
                y = x+d;
                dp[x][y] = INT32_MAX;
                for(int t = x; t < y; t++){
                    int a = dp[x][t];
                    int b = dp[t+1][y];
                    int c =(sum[y] - sum[x]);
                    if(x == 0){
                        temp = 0;
                    }else{
                        temp = sum[x-1];
                    }
                    dp[x][y] = min(dp[x][y], dp[x][t] + dp[t+1][y] + (sum[y] - temp));
                }
            }
        }
        cout << dp[0][k-1] << endl;
    }
    return 0;
}