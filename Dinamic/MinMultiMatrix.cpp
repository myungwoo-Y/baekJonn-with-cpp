#include<cstdio>
#include<algorithm>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
unsigned int dp[501][501];
int arr[501][2];
int main() {
    int n, end, addValue;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    for (int weight = 1; weight < n; ++weight) {
        for (int base = 1; base + weight <= n; ++base) {
            end = base + weight;
            dp[base][end] = UINT_MAX;
            for(int pivot = base; pivot < end; ++pivot){
                addValue = arr[base][0] * arr[pivot][1] * arr[end][1];
                dp[base][end] = min(dp[base][end],
                                    dp[base][pivot] + dp[pivot+1][end] + addValue);
            }
        }
    }

    printf("%u", dp[1][n]);

    return 0;
}



