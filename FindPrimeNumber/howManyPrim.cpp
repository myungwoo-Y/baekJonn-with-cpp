#include <iostream>
#include <bits/stdc++.h>
#include "math.h"
using namespace std;

void makePrimeArray(int inputNumber, bool isPrime[]){ // 에라토스테네스의 체를 이용하여 소수들을 구해 놓는다.
    int maxRange = inputNumber * 2;
    int sqrtNumber = sqrt(maxRange);
    isPrime[1] = false;
    isPrime[2] = true;
    if(inputNumber == 1 || inputNumber == 2) return;
    for(int index = 2; index <= maxRange; index++){
        if(isPrime[index]){
            for(int notPirmIndex = index + index; notPirmIndex <= maxRange; notPirmIndex += index){
                isPrime[notPirmIndex] = false;
            }
        }
    }

}

int getMax(vector<int> inputNumbers){  // 입력된 수 중 가장 큰 수를 찾는다.
    int max = inputNumbers[0];
    for(int index = 1; index < inputNumbers.size(); index++){
        if(max < inputNumbers[index]){
            max = inputNumbers[index];
        }
    }
    return max;
}

int main() {
    ios_base::sync_with_stdio(false);
    vector<int> inputNumbers;
    int inputNum = -1;
    bool isPrime[1000000];

    while(inputNum != 0){ // 0이 입력될 떄까지 값을 입력받는다.
        cin >> inputNum;
        if(inputNum != 0)
            inputNumbers.push_back(inputNum);
    }

    int max = getMax(inputNumbers);
    fill_n(isPrime, (max*2)+1, true);
    makePrimeArray(max, isPrime);  // 최댓값 범위만큼 소수들을 찾아놓는다.

    int size = inputNumbers.size();  // 각 숫자에 따른 범위에 소수가 몇개 있는지 찾는다.
    for(int index = 0; index < size; index++){
        int count = 0;
        int start = inputNumbers[index] + 1;
        int end = inputNumbers[index] * 2;
        int temp;
        for(int innerIndex = start; innerIndex <= end; innerIndex++){
            if(isPrime[innerIndex]){
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}