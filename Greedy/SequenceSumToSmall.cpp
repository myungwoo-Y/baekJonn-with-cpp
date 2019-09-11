#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>


using namespace std;

int main() {
    ios_base::sync_with_stdio();
    int d, sumMinus, sumNum = 0, indexDiffer;
    bool minusFlag = false;
    string str;
    vector<int> signalIndexs;
    cin >> str;
    for (int i = 0; i < str.length(); ++i) {
        if(str.at(i) == '-' || str.at(i) == '+'){
            signalIndexs.push_back(i);
        }
    }

    for (int i = 0; i < signalIndexs.size(); ++i) {
        if(minusFlag){
            sumNum += abs(stoi(str.substr(signalIndexs[i], 6))) * -1;
        }else{
            if(str.at(signalIndexs[i]) == '-'){
                minusFlag = true;
                sumNum += stoi(str.substr(signalIndexs[i], 6));
            } else{
                sumNum += stoi(str.substr(signalIndexs[i], 6));
            }
        }
    }
    if(str.at(0) != '-'){
        sumNum += stoi(str);
    }
    cout << sumNum;

    return 0;
}






