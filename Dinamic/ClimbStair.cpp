#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int stair[301];
    int dp[301];
    int stairSize;
    cin >> stairSize;

    fill_n(dp, 301, 0);

    for(int i = 1; i <= stairSize; i++){
        cin >> stair[i];
    }



    // 2 이하의 원소들은 for문에서 인덱스 오버이기 때문에
    // 따로 최댓값을 구해준다.
    dp[1] = stair[1];
    dp[2] = stair[2] + dp[1];

    // 점화식을 이용하여 최댓값을 구한다.
    for(int i = 3; i <= stairSize; i++){
        // 전 계단을 밟았다. 1번 전 계단값과 3번전 최댓값을 더해준다.
        // 세번전까지 구해주는 이유는 이번 계단이 연속 3번째 계단인 것을 방지하기 위해서이다.
        int back = stair[i] + stair[i-1] + dp[i-3];
        // 두번전 계단을 밝았을 경우이다.
        int twoBack = stair[i] + dp[i-2];
        dp[i] = max(back, twoBack);
    }

    cout << dp[stairSize];


    return 0;
}