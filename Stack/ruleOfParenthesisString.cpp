#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    char inputString[31];
    char stack[15];
    int stringSize;
    int sum = 0;
    int stackSize = 0;
    cin >> inputString;

    // 문자열 크기를 확인한다..
    for(stringSize = 0; inputString[stringSize]; stringSize++);

    // 문자열 내용을 확인하여 점수를 늘려간다.
    for(int i = 0; i < stringSize; i++){
        // 열린 괄호들은 스택에 쌓아준다.
        if(inputString[i] == '(' || inputString[i] == '['){
            stack[stackSize++] = inputString[i];

        }else if(inputString[i] == ')'){  // 닫힌 괄호의 경우이다.
            // 닫힌 괄호와 결합할 괄호가 있는지 확인하고 스택 사이즈가 정상인지 확인
            if(stack[stackSize -1] != '(' || stackSize < 0){
                // 비정상이면 출력값을 0으로 하게 조정해주고 반복을 끝낸다.
                stackSize = -1;
                break;
            }else if(inputString[i-1] == '('){
                // 전 문자열이 열린 괄호면 점수 시작점이다.
                int score = 2;
                // 스택에서 열린괄호를 지운다.
                stackSize--;
                // 스택에 쌓여있는 열린 괄호들을 기준으로 점수를 곱해나간다.
                for(int stackIndex = 0; stackIndex < stackSize; stackIndex++){
                    if(stack[stackIndex] == '('){
                        score *= 2;
                    }else{
                        score *= 3;
                    }
                }
                sum += score;
            }else{
                // 시작점이 아니면 무시해도 되므로 스택에서 원소를 지운다.
                stackSize--;
            }
        }else{
            if(stack[stackSize -1] != '[' || stackSize < 0){
                stackSize = -1;
                break;
            }else if(inputString[i-1] == '['){
                int score = 3;
                stackSize--;
                for(int stackIndex = 0; stackIndex < stackSize; stackIndex++){
                    if(stack[stackIndex] == '('){
                        score *= 2;
                    }else{
                        score *= 3;
                    }
                }
                sum += score;
            }else{
                stackSize--;
            }

        }
    }

    // 스택이 비어있을 때 최종 값을 출력한다.
    if(stackSize == 0){
        cout << sum ;
    }else{
        cout << 0;
    }

    return 0;
}