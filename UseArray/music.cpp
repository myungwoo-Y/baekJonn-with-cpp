//
// Created by myungwoo on 19. 1. 28.
//

#include <cstdio>
#include <iostream>

using namespace std;


int music(){
    char inputScales[100];
    for(int i=0; i < 8; i++)
    {
        cin >> inputScales[i];
    }

    int gap = (inputScales[1] - '0') - (inputScales[0] - '0');
    for(int index = 1; index < 7; index ++){
        if(gap != (inputScales[index+1] - '0') - (inputScales[index] - '0')){
            cout << "mixed" << endl;
            return 0;
        }
    }
    if(gap == 1){
        cout << "ascending" << endl;
    }else{
        cout << "descending" << endl;
    }
    return 0;
}

