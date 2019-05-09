//
// Created by myungwoo on 19. 2. 9.
//

#include <iostream>
using namespace std;

int findFraction(){

    bool isUp = true;
    int count ;
    int fraction[] = {1, 1};
    cin >> count;

    while(count > 1){
        if(isUp){
            fraction[0]--;
            fraction[1]++;
            if(fraction[0] == 0){
                fraction[0] = 1;
                isUp =false;
            }
        }else{
            fraction[0]++;
            fraction[1]--;
            if(fraction[1] == 0){
                fraction[1] = 1;
                isUp = true;
            }
        }
        count --;
    }

    cout << fraction[0] << '/' << fraction[1];
    return 0;
}




