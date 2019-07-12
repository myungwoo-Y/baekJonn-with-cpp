#include <iostream>
#include <vector>
#include "algorithm"
#include "math.h"
#include "ctime"

#define MAX 1000000000
using namespace std;

int main() {
    int n, sum = 0, one = 0, eight = 0;
    scanf("%d", &n);

    int dp[100][10] = {0};

    for(int i = 0; i < 10; i++){
        dp[0][i] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j+1] % MAX;
            }else if(j == 9){
                dp[i][j] = dp[i-1][j-1] % MAX;
            }else{
                dp[i][j] = (dp[i-1][j+1]) % MAX + (dp[i-1][j-1]) % MAX;
            }
        }
    }
    for(int i = 1; i < 10; i++){
        sum = ((dp[n-1][i]) % MAX + sum % MAX) % MAX;
    }
    printf("%d", sum);

    return 0;
}

