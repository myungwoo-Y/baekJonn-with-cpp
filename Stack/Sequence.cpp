#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void push(int s[], int& stackSize, int pushElement){
    s[stackSize++] = pushElement;
}


int main() {
    ios_base::sync_with_stdio(false);

    // 출력할 문자열 스트림이다.
    ostringstream outputStream;
    // 스택이다.
    int s[1000000];
    int stackSize = 0;
    // 넣을 원소
    int pushElement = 0;
    // 넣을 원소와 요구하는 값의 차이
    int difference = 0;
    // 입력 받을 값들 저장
    int inputNumbers[1000000];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> inputNumbers[i];
    }

    int i, inputNumber;

    for(i = 0; i < n; i++){
        inputNumber = inputNumbers[i];
        // 차이를 구한다.
        difference = inputNumber - pushElement;
        // 차이가 양수일경우
        if(difference >= 0){
            // 스택에 계속 push 해준다.
            for(int j = 0; j < difference; j++){
                outputStream << "+" << '\n';
                push(s, stackSize, ++pushElement);
            }
            // 찾는 원소는 무조건 pop 하기때문에 여기서 pop해준다.
            stackSize--;
            outputStream << "-" << '\n';
        }else{

            // 차이가 음수일 경우 pop해준다.
            // 스택은 내림차 순으로 쌓여있으니 같거나 작은 원소 찾을 때 까지 pop한다.
            // 단 스택 사이즈가 0보다 작아서 인덱스 잘못 접근하는것을 방지해준다.
            while(inputNumber < s[stackSize - 1] && stackSize > 0){
                outputStream << "-" << '\n';
                stackSize--;
            }

            // pop해야 되는데 사이즈가 0일경우, 찾는 원소를 발견 못할 경우 break 해준다.
            if(inputNumber != s[stackSize -1] || stackSize == 0){
                break;
            }else{  // 조건까지 pop한뒤 스택의 top에 원하는 원소가 있으면 한번더 pop해준다.
                outputStream << "-" << '\n';
                stackSize--;
            }
        }
    }

    if(i == n){
        cout << outputStream.str();
    }else{
        cout << "NO";
    }

    return 0;
}