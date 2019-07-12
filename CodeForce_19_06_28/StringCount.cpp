#include <iostream>
#include <vector>
#include "algorithm"
#include "math.h"

using namespace std;


int main() {

    char a[1000001], b[1000001];
    int sum = 0, lengthA, lengthB, oneInA=0, oneInB = 0;

    scanf("%s %s", a, b);

    for(lengthB = 0; b[lengthB]; lengthB++){
        if(b[lengthB] == '1'){
            oneInB++;
        }
    }


    for(lengthA = 0; a[lengthA]; lengthA++){
        if(lengthA < lengthB && a[lengthA] == '1'){
            oneInA++;
        }
    }

    for(int i = 0; i <= lengthA - lengthB; i++ ){
        if(oneInA % 2 == oneInB % 2){
            ++sum;
        }
        oneInA -= a[i] == '1' ? 1 : 0;
        oneInA += a[i+lengthB] == '1' ? 1 : 0;
    }
    printf("%d", sum);

    return 0;



}
 