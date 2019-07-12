#include <iostream>
#include <vector>
#include "ostream"
#include "algorithm"
#include "math.h"

using namespace std;

int main() {

    int n, temp, arr[100], g, difference[100];
    bool flag = true;
    scanf("%d", &n);
    double limit;
    vector<int> divisors;

    for(int i = 0; i < n; i++){
        scanf("%llu", &arr[i]);
    }

    sort(arr, arr+n, greater<int>());

    for(int i = 0; i < n-1; i++){
        difference[i] = arr[i] - arr[i+1];
    }

    g = n-1 > 1 ? gcd(difference[1], difference[0]) : difference[0];


    for(int i = 2; i < n-1; i++){
        g = gcd(g, difference[i]);
    }
    limit = sqrt(g);

    divisors.push_back(g);


    for(int divisor = 2 ; divisor <= limit && divisor < g; divisor++){
        if(g % divisor == 0){
            if(g / divisor == divisor){
                divisors.push_back(divisor);
            }else{
                divisors.push_back(divisor);
                divisors.push_back(g / divisor);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    for(int i = 0; i < divisors.size(); i++){
        printf("%d ", divisors[i]);
    }

//    printf("\n");
//
//    for(int i = 2; i < *max_element(arr, arr+n); i++){
//        flag = true;
//        temp = arr[0] % i;
//        for(int j = 1; j < n; j++){
//            if(arr[j] % i != temp){
//                flag = false;
//                break;
//            }
//        }
//        if(flag){
//            printf("%d ", i);
//        }
//    }

    return 0;
}

