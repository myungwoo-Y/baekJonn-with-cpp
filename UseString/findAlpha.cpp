//
// Created by myungwoo on 19. 1. 28.
//

#include <iostream>
using namespace std;


int findAlpha() {
    char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int numOfalpha[26];
    string inputChar;
    cin >> inputChar;
    fill_n(numOfalpha, 26, -1);
    for(int index = 0; index < inputChar.length(); index++){
        char comapreChar = inputChar.at(index);
        for(int alphIndex = 0; alphIndex < sizeof(alpha); alphIndex++){
            if(comapreChar == alpha[alphIndex] && numOfalpha[alphIndex] == -1){
                numOfalpha[alphIndex] = index;
            }
        }
    }

    for(int index = 0; index < 26; index++){
        cout << numOfalpha[index] << " ";
    }

    return 0;
}