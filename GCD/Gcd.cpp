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

int gcdMain() {

    long long int n, a, b, i;


    scanf("%llu %llu", &a, &b);
    i = gcd(a,b);

    printf("%llu\n", i);
    printf("%llu\n", (a*b)/i);


    return 0;
}


