#include<cstdio>
#include<algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;
int dp[101][100001];
int w[101];
int v[101];

int main() {
    int n, k, weight, value;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%d %d", &w[i], &v[i]);
    }

    for (int i = 1; i <= n; ++i) {
        weight = w[i];
        value = v[i];
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = dp[i-1][j];
            if(j - weight >= 0){
                dp[i][j] = max({value + dp[i-1][j-weight], dp[i-1][j]});
            }
        }
    }
    printf("%d", dp[n][k]);
    return 0;
}



int fistFalseCode(){
    int n, maxWeight, weight, value, addIndex;
    vector<pair<int, int>> arr;
    scanf("%d %d", &n, &maxWeight);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weight, &value);
        arr.push_back(pair<int, int>(weight, value));
    }
    sort(arr.begin(), arr.end());

    for (auto product: arr) {
        weight = product.first;
        value = product.second;
        for (int i = weight; i <= maxWeight; i++) {
            addIndex = i - weight;
            if (addIndex >= weight) {
                addIndex = weight - 1;
            }
            dp[i] = max({dp[i], value + dp[addIndex]});
        }
    }
    printf("%d", dp[maxWeight]);

}