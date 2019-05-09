//
// Created by myungwoo on 19. 1. 28.
//

#include <cstdio>
#include <iostream>

using namespace std;

void oxQuize(){
    int numOfexcute = 0;
    cin >> numOfexcute;
    while(numOfexcute > 0){
        char inputString[80];
        cin >> inputString;
        int score = 0, sumOfScore = 0;
        for(int index = 0; inputString[index]; index++){
            if(inputString[index] == 'O'){
                score += 1;
                sumOfScore += score;
            }else{
                score = 0;
            }
        }
        cout << sumOfScore << endl;
        numOfexcute --;
    }
}


