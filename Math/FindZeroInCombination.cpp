#include <algorithm>
#include <iostream>

using namespace std;

long long int fiveCount(long long int n){
    long long int sum {0}, powed {5};
    while(powed <= n){
        sum += n / powed;
        powed *= 5;
    }
    return sum;
}

long long int twoCount(long long int n){
    long long int sum {0}, powed {2};
    while(powed <= n){
        sum += n / powed;
        powed *= 2;
    }
    return sum;
}

int main()	{
    long long int n, m;
    cin >> n >> m;
    long long int fiveSum {0}, twoSum {0};
    fiveSum += fiveCount(n) - (fiveCount(m) + fiveCount(n - m));

    twoSum += twoCount(n) - (twoCount(m) + twoCount(n - m));

    cout << min(fiveSum, twoSum);

    return 0;
}