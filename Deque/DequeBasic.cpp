#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Deque{
    int maxSize, front, rear , size;
    int *deque;
    Deque(int inputSize){
        deque = new int[inputSize];
        maxSize = inputSize;
        size = 0;
        front = rear = -1;
    }
    int frontValue(){
        if(size == 0){
            return -1;
        }else{
            return deque[front];
        }
    }
    int rearValue(){
        if(size == 0){
            return -1;
        }else{
            return deque[rear];
        }
    }
    void push_front(int inputValue);
    void push_back(int inputValue);
    int pop_front();
    int pop_back();
    int sizeOfDeque(){
        return  size;
    }
    bool isEmpty(){
        return size == 0;
    }
};

// 원소를 앞에 집어넣는다.
void Deque::push_front(int inputValue) {
    if((front == 0 && rear == maxSize - 1) ||
            (rear == (front - 1))){
        return;
    }

    size++;
    if(front == -1){
        front = rear = 0;
        deque[front] = inputValue;
    }else if(front == 0){
        front = maxSize - 1;
        deque[front] = inputValue;
    }else{
        deque[--front] = inputValue;
    }
}


// 원소를 뒤에 집어넣는다.
void Deque::push_back(int inputValue) {
    if((front == 0 && rear == maxSize - 1) ||
            (rear == (front - 1))){
        return;
    }

    size++;
    if(front == -1){
        front = rear = 0;
        deque[rear] = inputValue;
    }else if(rear == maxSize - 1){
        rear = 0;
        deque[rear] = inputValue;
    }else{
        deque[++rear] = inputValue;
    }
}

// 앞의 원소를 제거한다.
int Deque::pop_front() {
    if(front == -1){
        return INT_MIN;
    }

    size--;
    int popValue = deque[front];

    if(rear == front){
        front = rear = -1;
    }else{
        front = (front + 1) % maxSize;
    }
    return popValue;
}

// 뒤의 원소를 제거한다.
int Deque::pop_back() {
    if(front == -1){
        return INT_MIN;
    }

    size--;
    int popValue = deque[rear];
    if(front == rear){
        front = rear = -1;
    }else if(rear == 0){
        rear = maxSize - 1;
    }else{
        rear--;
    }
    return popValue;
}



int main() {
    ios_base::sync_with_stdio(false);
    Deque deque(10000);
    int n;
    int inputValue;
    cin >> n;
    char inputChars[10];
    for(int i = 0; i < n; i++){
        cin >> inputChars;
        if(inputChars[0] == 'p'){
            if(inputChars[1] == 'u'){
                cin >> inputValue;
                if(inputChars[5] == 'f'){
                   deque.push_front(inputValue);
                }else{
                    deque.push_back(inputValue);
                }
            }else{
                if(deque.isEmpty()){
                    cout << -1 << "\n";
                    continue;
                }
                if(inputChars[4] == 'f'){
                    cout << deque.pop_front() << '\n';
                }else{
                    cout << deque.pop_back() << '\n';
                }
            }
        }else if(inputChars[0] == 's'){
            cout << deque.sizeOfDeque() << "\n";
        }else if(inputChars[0] == 'e'){
            if(deque.isEmpty()){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
        }else if(inputChars[0] == 'f'){
            cout << deque.frontValue() << "\n";
        }else{
            cout << deque.rearValue() << "\n";
        }
    }

    return 0;
}

















