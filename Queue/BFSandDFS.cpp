#include <iostream>
#include "ostream"
#include <bits/stdc++.h>

using namespace std;

struct Stack{
    int size;
    int *stack;
    Stack(int stackSize){
        stack = new int[stackSize];
        size = 0;
    }
    void push(int inputValue){
        stack[size++] = inputValue;
    }

    int peek(){
        if(size == 0){
            return INT_MIN;
        }else{
            return stack[size - 1];
        }
    }

    int pop(){
        if(size == 0){
            return INT_MIN;
        }else{
            return stack[--size];
        }
    }
};

struct Queue{
    int rear, front;

    int size;
    int *arr;

    Queue(int s){
        front = rear = -1;
        size = s;
        arr = new int[s];
    }
    bool isQueueEmpty(){
        return (front == -1 && rear == -1);
    }
    void push(int value);
    int pop();
};

void Queue::push(int value) {
    // 초과했는지 확인
    if((front == 0 && rear == size - 1) || (rear == (front-1)%(size-1))){
        return;
    // 비어있는지 확인
    }else if(front == -1){
        front = rear = 0;
        arr[rear] = value;
    // rear 변경해야 되는지 확인
    }else if(front != 0 && rear == size - 1){
        rear = 0;
        arr[rear] = value;
    // 나머지는 원래 큐대로 넣
    }else{
        arr[++rear] = value;
    }
}


int Queue::pop() {
    // 비어있는지 확인
    if(front == -1){
        return INT_MIN;
    }

    int returnData = arr[front];
    arr[front] = -1;
    // 원소가 1개인지 확인 -> 초기 상태로 되돌린다.
    if (front == rear){
        front = -1;
        rear = -1;
    // front를 옮겨 줘야 되는지 확
    } else if (front == size - 1)
        front = 0;
    // 나머지는 그대로 행한다.
    else
        front++;
    return returnData;
}


int main() {
    ios_base::sync_with_stdio(false);
    ostringstream outputStream;

    int numberOfEdge, numberOfVertex, startVertex;
    cin >> numberOfVertex >> numberOfEdge >> startVertex;
    // 정점 관계를 초기화한다.
    bool vertices[1001][1001] = { false };
    // 정점 관계를 입력 받는다.
    for(int i = 0; i < numberOfEdge; i++){
        int row, col;
        cin >> row >> col;
        vertices[row][col] = vertices[col][row] = true;
    }
    Stack stack(2000);
    Queue queue(2000);
    stack.push(startVertex);
    queue.push(startVertex);

    // 방문 기록을 초기화 한다.
    bool isVisit[numberOfVertex + 1] = {false};
    isVisit[startVertex] = true;


    outputStream << startVertex << " ";
    // 스택이 빌 때까지 반복한다.
    while(stack.size != 0){
        int topVertex = stack.peek();
        // 방문한 점이 아닐 떄만 추가한다.
        if(!isVisit[topVertex]){
            outputStream << topVertex << " ";
        }
        // 꺼낸 점을 방문 했다고 체크한다.
        isVisit[topVertex] = true;
        // 인접 정점들중 방문 안한 정점이 한개라도 있으면 스택에 원소를 쌓는다.
        for(int i = 1; i < numberOfVertex + 1 ; i++){
            if(vertices[topVertex][i] && !isVisit[i]){
                stack.push(i);
                break;
            }
        }
        // 원소를 push 하지 않았을 경우만 pop해준다.
        if(topVertex == stack.peek()){
            stack.pop();
        }
    }
    cout << outputStream.str() << "\n";

    outputStream = ostringstream();

    // 초기화 해준다.
    fill_n(isVisit, numberOfVertex + 1, false);
    isVisit[startVertex] = true;
    while(!queue.isQueueEmpty()){
        // 원소를 꺼낸다.
        int frontVertex = queue.pop();
        outputStream << frontVertex << " ";
        // 원소의 인접 정점을 큐에 집어넣어주고 방문했다고 체크한다.
        for(int i = 1; i < numberOfVertex + 1 ; i++){
            if(vertices[frontVertex][i] && !isVisit[i]){
                queue.push(i);
                isVisit[i] = true;
            }
        }
    }


    cout << outputStream.str();





    return 0;
}