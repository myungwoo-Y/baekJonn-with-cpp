#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//typedef  struct node node;
//struct node{
//    int value;
//    node* nextNode;
//};
//
//struct  Queue{
//    node* newNode = new node;
//    int capacity,  size = 0;
//    node* front, rear;
//    void push(int pushValue){
//        if(size == 0){
//        }
//    }
//
//};
typedef struct  node node;
// 이름으로 선언과 동시에 할당되는 노드들이다.
struct node
{
    int data;
    node* next;
}*front = NULL, *rear = NULL, *p = NULL, *np = NULL;
int size;

void push(int x)
{
    np = new node;
    np->data = x;
    np->next = NULL;
    if(front == NULL){
        front = rear = np;
        rear->next = NULL;
    }else{
        rear->next = np;
        rear = np;
        rear->next = NULL;
    }
    size++;
}

int pop(){
    int x;
    if(size == 0){
        cout << -1 << "\n";
    }else if(size == 1){
        int number = front->data;
        front = rear = NULL;
        size --;
        cout << number << '\n';
    }else{
        int number = front->data;
        front = front->next;
        size --;
        cout << number << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    char inputChars[10];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> inputChars;
        if(inputChars[0] == 'p'){
            if(inputChars[1] == 'u'){
                int inputNumber ;
                cin >> inputNumber;
                push(inputNumber);
            }else{
                pop();
            }
        }else if(inputChars[0] == 's'){
            cout << size << '\n';
        }else if(inputChars[0] == 'e'){
            if(size > 0){
                cout << 0 << '\n';
            }else{
                cout << 1 << '\n';
            }
        }else if(inputChars[0] == 'f'){
            if(size == 0){
                cout << -1 << '\n';
            }
            else{
                cout << front->data << '\n';
            }
        }else{
            if(size == 0){
                cout << -1 << '\n';
            }else{
                cout << rear->data << '\n';
            }
        }
    }
    return 0;
}