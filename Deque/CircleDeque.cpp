#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Deque {
    int maxSize, front, rear, size;
    int *deque;

    Deque(int inputSize) {
        deque = new int[inputSize];
        maxSize = inputSize;
        size = 0;
        front = rear = -1;
    }

    int frontValue() {
        if (size == 0) {
            return -1;
        } else {
            return deque[front];
        }
    }

    int rearValue() {
        if (size == 0) {
            return -1;
        } else {
            return deque[rear];
        }
    }

    void circleLeft() {
        push_back(pop_front());
    }

    void circleRight() {
        push_front(pop_back());
    }

    // 왼쪽으로 원소를 옮길지 판별한다.
    bool isLeft(int value) {
        int index = front;
        int count;
        // 원소를 찾기위해 몇번 움직여야 하는지 찾는다
        for (count = 0; count < size; count++) {
            if(index == maxSize){
                // 인덱스 초과이면 0으로 만들어준다.
                index = 0;
            }
            // 값을 찾으면 반복을 멈춘다.
            if (deque[index] == value) {
                break;
            }
            // 다음 원소를 확인하기 위하여 인덱스를 증가시킨다.
            index++;
        }
        return ((size / 2) - count) >= 0;
    }

    void push_front(int inputValue);

    void push_back(int inputValue);

    int pop_front();

    int pop_back();

    int sizeOfDeque() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }
};

// 원소를 앞에 집어넣는다.
void Deque::push_front(int inputValue) {
    if ((front == 0 && rear == maxSize - 1) ||
        (rear == (front - 1))) {
        return;
    }

    size++;
    if (front == -1) {
        front = rear = 0;
        deque[front] = inputValue;
    } else if (front == 0) {
        front = maxSize - 1;
        deque[front] = inputValue;
    } else {
        deque[--front] = inputValue;
    }
}


// 원소를 뒤에 집어넣는다.
void Deque::push_back(int inputValue) {
    if ((front == 0 && rear == maxSize - 1) ||
        (rear == (front - 1))) {
        return;
    }

    size++;
    if (front == -1) {
        front = rear = 0;
        deque[rear] = inputValue;
    } else if (rear == maxSize - 1) {
        rear = 0;
        deque[rear] = inputValue;
    } else {
        deque[++rear] = inputValue;
    }
}

// 앞의 원소를 제거한다.
int Deque::pop_front() {
    if (front == -1) {
        return INT_MIN;
    }

    size--;
    int popValue = deque[front];

    if (rear == front) {
        front = rear = -1;
    } else {
        front = (front + 1) % maxSize;
    }
    return popValue;
}

// 뒤의 원소를 제거한다.
int Deque::pop_back() {
    if (front == -1) {
        return INT_MIN;
    }

    size--;
    int popValue = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = maxSize - 1;
    } else {
        rear--;
    }
    return popValue;
}


void quickSort(int left, int right, int arr[]) {
    int start = left;
    int end = right;
    int pivot = arr[(left + right) / 2];
    do {
        while (arr[left] < pivot) left++;
        while (arr[right] > pivot) right--;
        if (left <= right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    } while (left < right);

    if (start < right) {
        quickSort(start, right, arr);
    }

    if (left < end) {
        quickSort(left, end, arr);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    int dequeSize, numberOfFind, cnt = 0;
    int numberOfLoop = 0;
    cin >> dequeSize >> numberOfFind;

    Deque deque(dequeSize);

    int inputNumbers[numberOfFind];

    // 찾을 수를 배열에 저장한다.
    for (int i = 0; i < numberOfFind; i++) {
        cin >> inputNumbers[i];
    }

    // 원소를 차례대로 deque 에 넣어준다.
    for (int i = 1; i <= dequeSize; i++) {
        deque.push_back(i);
    }

    //quickSort(0, numberOfFind - 1, inputNumbers);

    while (cnt < numberOfFind) {
        // 찾는 수를 저장한다.
        int findNumber = inputNumbers[cnt];
        // 첫번째 수가 찾는 수이면 pop하여 꺼내준다.
        if (inputNumbers[cnt] == deque.frontValue()) {
            // 첫번째수 이므로 loop 횟수를 증가시키진 않는다.
            deque.pop_front();
            cnt++;
        // 그렇지 않으면 왼쪽 옮길 것인지 확인한다.
        } else if (deque.isLeft(findNumber)) {
            deque.circleLeft();
            numberOfLoop++;
        } else {
            deque.circleRight();
            numberOfLoop++;
        }
    }
    // loop 횟수를 출력한다.
    cout << numberOfLoop;
    return 0;
}