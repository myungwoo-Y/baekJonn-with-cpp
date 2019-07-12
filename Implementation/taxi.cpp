#include <iostream>
#include "ostream"
#include "algorithm"
#include "math.h"
using namespace std;

int taxi() {
    double r;

    cin >> r;
    cout.precision(7);
    printf("%.6f\n", r * r * M_PI);
    printf("%.6f\n", r * r * 2);
    return 0;
}