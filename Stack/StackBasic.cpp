#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void push(int stack[],int inputNum ,int& size){
    stack[size++] = inputNum;
}

void pop(int stack[] ,int& size){
    if(size == 0){
        cout << -1 << "\n";
        return;
    }
    cout << stack[size - 1] << "\n";
    size --;
}

void stackSize(int& size){
    cout << size << "\n";
}

void empty(int& size){
    if(size == 0){
        cout << 1 << "\n";
    }else{
        cout << 0 << "\n";
    }
}

int top(int stack[], int& size){
    if(size == 0){
        cout << -1 << "\n";
    }else{
        cout << stack[size - 1] << "\n";
    }
}


// 문자열 비교시 모든 문자 비교말고 한문자씩 비교하면 더 좋았을 것이다.
// 무조건 string 대신 char 배열의 타당성도 검토해보자.

int main() {
    ios_base::sync_with_stdio(false);
    int n ;
    int stack[10001];
    int size = 0;
    size_t index = 0;
    string delimiter = " ";
    string name;
    cin >> n;

    string inputString;
    for(int i = 0; i < n; i++){
        cin >> inputString;
        name = inputString;
        if(name == "push"){
            cin >> inputString;
            push(stack, stoi(inputString), size);
        }else if(name == "pop"){
            pop(stack, size);
        }else if(name == "size"){
            stackSize(size);
        }else if(name == "empty"){
            empty(size);
        }else if(name == "top"){
            top(stack, size);
        }
    }
    return 0;
}