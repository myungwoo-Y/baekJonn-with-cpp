#include<cstdio>
#include<algorithm>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
int dp[501][501];
int sum[501];
int main() {
    int n, fileNumber, end;
    scanf("%d", &n);
    for (; n > 0; --n) {
        scanf("%d", &fileNumber);
        for(int i = 1; i <= fileNumber; i++){
            scanf("%d", &sum[i]);
            sum[i] += sum[i-1];
        }
        // 기존 값과 차이를 1 부터 최대까지 하여 조사
        for (int weight = 1; weight < fileNumber; ++weight) {
            // 1번째 책부터 최대 번호 책까지 차이에 대한 최솟값 구한다.
            for (int base = 1; base + weight <= fileNumber; ++base) {
                end = base+weight;
                dp[base][end] = INT_MAX;
                // 범위 내에서 구간을 2분할 수 있는 :모든 경우의 값을 구하여 나온 최솟값 저장
                for (int pivot = base; pivot < end; ++pivot) {
                    dp[base][end] = min(dp[base][end],
                                        dp[base][pivot] + dp[pivot+1][end] + (sum[end] - sum[base-1]));
                }
            }
        }
        printf("%d\n", dp[1][fileNumber]);
    }
    return 0;
}



