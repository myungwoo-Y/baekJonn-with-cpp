//
// Created by myungwoo on 19. 1. 29.
//

#include <iostream>
#include "string"
using namespace std;

int run(){
    char inputString[15];
    int sum = 0;
    cin >> inputString;

    // 대부분은 3으로 나누어서 처리가 가능하지만 그 이외의 경우에는 따로 예외처리를 해준다.
    for(int index = 0; inputString[index]; index++){
        int numberOfchar = ((inputString[index] - 'A') / 3) + 2;
        if(inputString[index] == 'S'){
            sum += 7+1;
        }else if(inputString[index] == 'V'){
            sum += 8+1;
        }else if(numberOfchar > 9){
            sum += 9+1;
        }else{
            sum += numberOfchar+1;
        }
    }

    cout << sum;

    return 0;
}

