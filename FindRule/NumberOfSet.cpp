//
// Created by myungwoo on 19. 2. 11.
//

#include <iostream>
using namespace std;

int countNumber[10];
char inputNumbers[1000001];
int count;
void countAdd(int plusNumber){
    for(int index = 0; index < 10; index++){
        countNumber[index] ++;
    }
    countNumber[plusNumber] --;
    count ++;
}
int numberOfSet(){
    int number;
    cin >> inputNumbers;
    for(int index = 0; inputNumbers[index]; index++){
        number = inputNumbers[index] - '0';
        if(countNumber[number] == 0){
            if(number == 9 && countNumber[6] != 0){
                countNumber[6]--;
            }else if(number == 6 && countNumber[9] != 0){
                countNumber[9]--;
            }else{
                countAdd(number);
            }
        }else{
            countNumber[number]--;
        }
    }
    cout << count;
    return 0;
}





