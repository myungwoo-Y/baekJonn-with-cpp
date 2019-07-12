#include <iostream>
#include <vector>
#include "ostream"
#include "algorithm"
#include "math.h"

using namespace std;


int minSum() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int arr[100000];
    int dp[100000];
    unsigned long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    for(int i = 1; i < n; i++){
        dp[i] = max({arr[i], dp[i-1] + arr[i]});
    }

    cout << *max_element(begin(dp), dp+n);

    return 0;
}