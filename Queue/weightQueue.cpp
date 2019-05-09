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

void quickSort(int left, int right, int arr[]){
    int start = left;
    int end = right;
    int pivot = arr[(left + right) / 2];
    do{
        while(arr[left] > pivot) left++;
        while(arr[right] < pivot) right--;
        if(left <= right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }while(left < right);
    if(start < right)
        quickSort(start, right, arr);
    if(left < end)
        quickSort(left, end, arr);

}


int main() {
    ios_base::sync_with_stdio(false);
    ostringstream outputStream;
    int n;
    cin >> n;
    for(int k = 0; k < n; k++){
        Queue queue(5000);
        int numberOfDacu, findNumber;
        cin >> numberOfDacu >> findNumber;
        // 가중치
        int weights[numberOfDacu]; 
        // 정렬된 가중치
        int sortedWeight[numberOfDacu];
        // 가줃치를 입력 받으면서 정렬된 가중치 그래프도 초기화한다.
        // 이때 큐에 원소도 집어넣어준다.
        for(int i = 0; i < numberOfDacu; i++){
            cin >> weights[i];
            sortedWeight[i] = weights[i];
            queue.push(i);
        }
        // 가중치들을 정렬해준다.
        quickSort(0, numberOfDacu - 1, sortedWeight);
        int sequence = 0;
        // 큐에 원소가 없을 때 까지 반복한다.
        while(queue.rear != -1 || queue.front != -1){
            // 큐에서 꺼낸 원소
            int popNumber = queue.pop();
            // 꺼낸 원소 가중치를 확인해서 가장 큰 가중치가 아니면 다시 큐에 넣는다.
            if(weights[popNumber] < sortedWeight[sequence]){
                queue.push(popNumber);
            // 그렇지 않으면 큐에서 원소를 뺴는데 이 원소가 찾는 원소인지 확인한다.
            }else if(weights[popNumber] == sortedWeight[sequence]){
                if(popNumber == findNumber){
                    // 찾는 원소이면 그만둔다.
                    break;
                }else{
                    // 원소를 한개 pop 했기 때문에 , 출력할 순서를 증가시킨다.
                    sequence++;
                }
            }
        }

        cout << sequence + 1 << "\n";


    }

    return 0;
}