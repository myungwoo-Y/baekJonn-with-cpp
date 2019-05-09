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

    void reverse() {
        int temp = front;
        front = rear;
        rear = temp;
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


int main() {
    ios_base::sync_with_stdio(false);
    int testCase = 0;
    cin >> testCase;
    // testCase 만큼 반복한다.
    while (testCase > 0) {
        char inputChars[400005], inputFuntions[100001];
        int dequeSize, charIndex, pushValue;
        bool reverseFlag = false;
        bool errorFlag = false;
        ostringstream outputStream;

        cin >> inputFuntions >> dequeSize >> inputChars;
        Deque deque(dequeSize);

        charIndex = 1;
        for (int i = 0; i < dequeSize; i++) {
            //pushValue = inputChars[charIndex] - '0';
            char nextChar, currnetChar;
            int mulValue = 1;
            int pushValue = 0;

            // 문자열에서 숫자를 추출한다.
            do{
                currnetChar = inputChars[charIndex];
                nextChar = inputChars[charIndex + 1];
                pushValue *= mulValue;
                pushValue += (currnetChar - '0');
                mulValue = 10;
                charIndex++;
            }while((nextChar >= '0') && (nextChar <= '9'));
            // 다음 문자로 넘어가기 위해 인덱스를 늘려준다.
            charIndex ++;
            // 추출한 값을 deque에 넣어준다.
            deque.push_back(pushValue);
        }

        // 함수를 해석하여 작동시킨다.
        for (int i = 0; inputFuntions[i]; i++){
            if(inputFuntions[i] == 'R'){
                // 플래그를 변화시킨다.
                reverseFlag = !reverseFlag;
            }else{
                if(deque.isEmpty()){
                    errorFlag = true;
                    break;
                }else{
                    // 플래그에 따라 다르게 빼낸다.
                    if(!reverseFlag){
                        deque.pop_front();
                    }else{
                        deque.pop_back();
                    }
                }
            }
        }

        // deque 가 빌 때 까지 deque 원소를 꺼내 스트림에 써준다.
        while (!deque.isEmpty()){
            if(!reverseFlag){
                outputStream << deque.pop_front() << ",";
            }else{
                outputStream << deque.pop_back() << ",";
            }
        }

        string outputString = outputStream.str();

        // 플래그를 확인하여 그에 맞게 출력한다.
        if(errorFlag)
            cout << "error" << "\n";
        else
            cout << "[" << outputString.substr(0, outputString.size() - 1) << "]" << '\n' ;

        testCase--;
    }

    return 0;
}
























