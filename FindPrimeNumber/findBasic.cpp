#include <iostream>
#include <bits/stdc++.h>
#include "math.h"

using namespace std;

int main() {
    int n;
    int count = 0;
    int number;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> number;
        if(number == 1){
            continue;
        }

        for (int divideNumber = 2; divideNumber <= sqrt(number); divideNumber++) {
            if ((number % divideNumber) == 0) {
                count--;
                break;
            }
        }

        count++;
    }

    cout << count;
    return 0;
}