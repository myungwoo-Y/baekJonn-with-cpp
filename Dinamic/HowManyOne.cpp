#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    int targetNumber, dividedIndex, dividedThree, dividedTwo;
    // 동적 할당을 할 배열을 초기화한다.
    int dp[1000001] = {0};

    // 목표 수를 저장한다.
    cin >> targetNumber;

    // 목표 수까지 1부터 값을 계산 해나간다.
    for (int i = 2; i <= targetNumber; i++) {
        // 현재 주어진 수가 2와 3 모두 나눠지는지 확인
        if((i % 2) == 0 && (i % 3) == 0){
            dividedTwo = i / 2;
            dividedThree = i / 3;
            // 확인하여 올려준다.
            dividedIndex = dp[dividedTwo] < dp[dividedThree]
                           ? dividedTwo : dividedThree;
        } else if ((i % 2) == 0) {
            dividedIndex = i / 2;
        } else if ((i % 3) == 0) {
            dividedIndex = i / 3;
        } else {
            dividedIndex = -1;
        }
        if (dividedIndex > 0) {
            dp[i] = dp[dividedIndex] < dp[i - 1]
                    ? dp[dividedIndex] + 1 : dp[i - 1] + 1;
        }else{
            dp[i] = dp[i - 1] + 1;
        }
    }

    cout << dp[targetNumber];

    return 0;
}