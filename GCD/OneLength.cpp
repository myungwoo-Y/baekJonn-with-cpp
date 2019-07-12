//
// Created by auddn on 2019-06-25.
//
#include <iostream>
#include <vector>
#include "ostream"
#include "algorithm"
#include "math.h"

using namespace std;
long long int gcd(long long int a, long long int b) {
    if (a % b == 0) return b;
    else gcd(b, a % b);
}
int oneLength() {

    long long int a, b, maxLength, minLength, i, printCount;

    scanf("%llu %llu", &a, &b);
    maxLength = max(a, b);
    minLength = min(a, b);

    printCount = gcd(maxLength, minLength);
    for (int i = 0; i < printCount; i++) {
        printf("1");
    }
    return 0;
}


