#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


string strMul(string str, int n){
    string result {""};
    for (int i = 0; i < n; ++i) {
        result += str;
    }
    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt {0};
    string inputStr {""}, resultStr {""}, a {"AAAA"}, b {"BB"};

    cin >> inputStr;

    for (int i = 0; i < inputStr.length(); ++i) {
        if(inputStr.at(i) == '.'){
            if(cnt != 0){
                if(cnt % 2 != 0){
                    resultStr = "-1";
                    break;
                }
                resultStr += strMul(a, cnt/4);
                resultStr += strMul(b, (cnt%4)/2);
            }
            cnt = 0;
            resultStr += ".";
        }else{
            cnt++;
        }
    }

    if(cnt != 0 && resultStr.compare("-1") != 0){
        if(cnt % 2 != 0){
            resultStr = "-1";

        }else{
            resultStr += strMul(a, cnt/4);
            resultStr += strMul(b, (cnt%4)/2);
        }
    }

    cout << resultStr;
    return 0;
}