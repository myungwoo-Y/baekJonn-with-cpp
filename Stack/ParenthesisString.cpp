#include <iostream>
#include <bits/stdc++.h>

using namespace std;




int main() {
    ios_base::sync_with_stdio(false);
    int n;
    int size;
    char inputString[51];

    cin >> n;
    // ( 가 발견되면 사이즈 증가시키고, ) 이면 사이즈를 감소시켰다.
    for(int number = 0; number < n; number++){
        int i = 0;
        size = 0;
        cin >> inputString;
        while(inputString[i]){
            if(inputString[i] == '('){
                size++;
            }else{
                size--;
                if(size < 0){
                    break;
                }
            }
            i++;
        }
        if(size == 0){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }


    return 0;
}