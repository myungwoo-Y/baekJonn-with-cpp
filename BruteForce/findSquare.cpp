#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stack>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int start = sqrt(n);
    
    if(start*start == n){
        cout << 1;
        return 0;
    }


    int t1, t2, t, sum = INT32_MAX, tempSum;
    for (int i = (int) sqrt(n / 4); i * i <= n; i++) {
        t1 = n - i * i;
        for (int j = (int) sqrt(t1 / 3); j <= i && j * j <= t1; j++) {
            t2 = t1 - j * j;
            for (int k = (int) sqrt(t2 / 2); k <= j && k * k <= t2; k++) {
                t = (int) sqrt(t2 - k * k);
                if (t <= k && t * t == t2 - k * k) {
                    tempSum = (i != 0) + (j != 0) + (k != 0) + (t != 0);
                    sum = min(sum, tempSum);
                }
            }
        }
    }

    cout << sum;
    return 0;
}









