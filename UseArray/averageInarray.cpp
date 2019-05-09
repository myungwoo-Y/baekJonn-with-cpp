//
// Created by myungwoo on 19. 1. 28.
//
#include <iostream>

using namespace std;
void average(){
    int studentsScoer[5];
    int sumOfScore = 0;
    for(int index = 0; index < 5; index++){
        cin >> studentsScoer[index];
        sumOfScore += studentsScoer[index];
    }
    cout << sumOfScore / 5 << endl;
}

