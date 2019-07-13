#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
    int n, dp[100], a[100][2], index, target;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a[i][0], &a[i][1]);
        dp[i] = 1;
    }

    // bubble sort
    for(int i = 1; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            if(a[j][0] > a[j+1][0]){
                index = a[j][0];
                target = a[j][1];
                a[j][0] = a[j+1][0];
                a[j][1] = a[j+1][1];
                a[j+1][0] = index;
                a[j+1][1] = target;
            }
        }
    }

    //LIS search
    for(int i = 1; i < n; i++) {
        for (int j = 0; j < i; ++j) {
            if(a[i][1] > a[j][1]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    printf("%d", n - *max_element(dp, dp+n));
    return 0;
}