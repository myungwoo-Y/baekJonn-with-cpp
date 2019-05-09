#include <iostream>
#include "ostream"
#include <bits/stdc++.h>

using namespace std;

struct Queue{
    int rear, front;

    int size;
    int *arr;

    Queue(int s){
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void push(int value);
    int pop();
};

void Queue::push(int value) {
    if((front == 0 && rear == size - 1)){
        return;
    }else if(front == -1){
        front = rear = 0;
        arr[rear] = value;
    }else if(front != 0 && rear == size - 1){
        rear = 0;
        arr[rear] = value;
    }else{
        arr[++rear] = value;
    }
}


int Queue::pop() {
   if(front == -1){
       return INT_MIN;
   }

   int returnData = arr[front];
   arr[front] = -1;
   if (front == rear){
       front = -1;
       rear = -1;
   } else if (front == size - 1)
       front = 0;
   else
       front++;
   return returnData;
}


int main() {
    ios_base::sync_with_stdio(false);
    ostringstream outputStream;
    Queue queue(5000);
    int n, rule, count = 1;
    cin >> n >> rule;
    for(int i = 1; i <= n; i++){
        queue.push(i);
    }

    outputStream << "<";

    do{
        if(count % rule != 0){
            queue.push(queue.pop());
        }else{
            outputStream << queue.pop() << ", ";
        }
        count ++;
    }while(queue.front != -1);

    string outputString = outputStream.str();
    cout << outputString.substr(0, outputString.size() - 2) << ">";

    return 0;
}