//
// Created by myungwoo on 19. 1. 29.
//

// 가장 많이 등장하는 문자를 출력하는 프로그램
// 가장 많이 등장하는 문자가 여러개면 ? 를 출력한다.
#include <iostream>
using namespace std;

int find(){
    char inputChar[1000001];
    cin >> inputChar;
    int alphIndex[26];
    fill_n(alphIndex, 26, 0);

    for(int index = 0; inputChar[index]; index++){
        char indexChar = inputChar[index];
        if(indexChar <= 'Z'){
            alphIndex[indexChar - 'A']++;
        }else{
            alphIndex[indexChar - 'a']++;
        }
    }

    int max = 0;
    for(int index = 0; index < 26; index++){
        if(alphIndex[index] > alphIndex[max]){
            max = index;
        }
    }

    int cnt = 0;
    for(int index = 0; index < 26; index++){
        if (alphIndex[index] == alphIndex[max]) {
            cnt ++;
        }
    }

    if(cnt > 1){
        cout << "?";
    }else{
        cout << (char) (max + 'A');
    }
    return 0;
}

