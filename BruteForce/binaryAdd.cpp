#include <iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#define endl '\n'
using namespace std;

// string을 vector 로 변화시킨다.
void stringToVector(vector<int>& list, string str){
    for (int i = 0; i < str.length(); ++i) {
        list.push_back(str.at(i)-48);
    }
}

// 문자열을 기반으로 더한다.
string add(vector<int>& listA, vector<int>& listB){
    string result {""};

    int digitA = listA.size() - 1, digitB = listB.size() - 1;

    int add {0}, sum {0};

    // 각이진수의 첫자리부터 시작하여 계산한다.
    while(digitA >= 0 || digitB >= 0){
        if(digitA >= 0 && digitB >= 0){
            sum = listA[digitA] + listB[digitB] + add;

            // 올림이 있는 경우
            if(sum > 1){
                result.insert(0, to_string(sum%2));
                add = 1;
            }else{
                result.insert(0, to_string(sum));
                add = 0;
            }
            digitA--;
            digitB--;
        }else if(digitA >= 0){
            sum = listA[digitA] + add;
            if(sum > 1){
                result.insert(0, to_string(sum%2));
                add = 1;
            }else{
                result.insert(0, to_string(sum));
                add = 0;
            }
            digitA--;
        }else if(digitB >= 0){
            sum = listB[digitB] + add;
            if(sum > 1){
                result.insert(0, to_string(sum%2));
                add = 1;
            }else{
                result.insert(0, to_string(sum));
                add = 0;
            }
            digitB--;
        }
    }

    // 마지막 연산에서 올림수가 있으면 이를 추가한다.
    if(add == 1){
        result.insert(0, to_string(add));
    }
    return result;
}


// 이진수 앞의 0을 제거한다.
void checkZeroInFront(string str){
    bool notPrint = true;
    for (int i = 0; i < str.length(); ++i) {
        if(str.at(i) != '0' && notPrint){
            notPrint = false;
        }

        if(!notPrint){
            cout << str.at(i);
        }
    }

    // 결과가 0일 경우 그냥 0만 출력한다.
    if(notPrint){
        cout << 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a {""}, b {""};
    cin >> a >> b;

    vector<int> listA, listB;

    stringToVector(listA, a);
    stringToVector(listB, b);

    string result = add (listA, listB);

    checkZeroInFront(result);

    return 0;
}





