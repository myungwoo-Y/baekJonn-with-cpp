#include <iostream>
#include "ostream"
#include "algorithm"
#include "math.h"
using namespace std;

int padovanSequence() {

    unsigned long dp[100];
    for(int i = 0; i < 5; i++){
        dp[i] = (i >= 3) + 1;
    }

    int n, k;
    cin >> n;
    for(int i = 5; i < 100; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }

    for(int i = 0; i < n; i++){
        cin >> k;
        cout << dp[k-1] << "\n";
    }

    return 0;
}