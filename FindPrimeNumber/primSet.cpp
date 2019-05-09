#include <iostream>
#include <bits/stdc++.h>
#include "math.h"
using namespace std;

void getPrime(int inputNumber, bool isPrime[]){  // 아리스토텔레스의 체를 이용하여 소수들을 구한다.
    int sqrtNumber = sqrt(inputNumber);
    for(int index = 2; index <= sqrtNumber; index++){
        if(isPrime[index]){
            for(int notPrime = index*2; notPrime < inputNumber; notPrime += index){
                isPrime[notPrime] = false;
            }
        }
    }
}

void getMax(vector<int> inputNumbers, int& max){ // 입력된 값들중 최댓값을 구한다.
    max = inputNumbers[0];
    for(int index = 1; index < inputNumbers.size(); index++){
        if(max < inputNumbers[index]){
            max = inputNumbers[index];
        }
    }
}

int nearPrime(int number, bool isPrime[]){  // 근처에 있는 소수를 구한다.
    while(!isPrime[number]){
        number--;
    }
    return number;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, max;
    bool isPrime[1000000];

    cin >> n;
    isPrime[1] = false;
    vector<int> inputNumbers(n);
    for(int i = 0; i < n; i++){  // 수들을 입력 받는다.
        cin >> inputNumbers[i];
    }
    getMax(inputNumbers, max);
    fill_n(isPrime, max, true);

    getPrime(max, isPrime);  // 최댓값을 범위로 하여 소수를 찾는다.

    for(int index = 0; index < inputNumbers.size(); index++){  // 쌍 끼리 차가 적은 소수부터 찾아 맞는 쌍인지 확인 
        int inputNumber = inputNumbers[index];
        int primeNumber = nearPrime(inputNumber / 2 , isPrime);  // 수의 중간 값에서 가장 가까운 소수를 구한다.
        int backPrimeNumber;  // 입력 수에서 방금 구한 소수를 빼면 차이가 가장 작은 소수 쌍을 구할 수 있다.
        while(primeNumber != 1){
            backPrimeNumber = inputNumber - primeNumber;
            if(isPrime[backPrimeNumber]){ 
                break;
            }else{  // 뺸 수가 소수가 아니라면 바로 전의 소수를 구한다.
                primeNumber = nearPrime(primeNumber-1, isPrime);
            }
        }
        cout << primeNumber << " " << backPrimeNumber << "\n";
    }
    return 0;
}