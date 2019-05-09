//
// Created by myungwoo on 19. 2. 12.
//

#include <iostream>
#include "cstdlib"
using namespace std;

int calender(){
    int numberOfOperation;
    cin >> numberOfOperation;
    while(numberOfOperation > 0){
        int m, n, x, y, difference, base, nextY, countYear, maxYear;
        bool isPrint = true;
        cin >> m >> n >> x >> y;
        difference = m - n;

        nextY = m % n;
        maxYear = m;
        do{
            nextY = nextY + difference;
            if(nextY <= 0){
                nextY += n;
            }else{
                nextY %= n;
                if(nextY == 0) nextY = n;
            }
            maxYear += m;


        }while(n != nextY);

        nextY = x % n;
        if(nextY == 0) nextY = n;
        countYear = x;
        do{
            if(nextY == y){
                cout << countYear << endl;
                isPrint = false;
                break;
            }
            nextY = nextY + difference;
            if(nextY <= 0){
                nextY += n;
            }else{
                nextY %= n;
                if(nextY == 0) nextY = n;
            }
            //cout << nextY << endl;
            countYear += m;
            if(y == nextY && countYear <= maxYear){
                cout << countYear << endl;
                isPrint = false;
                break;
            }
        }while(countYear < maxYear);

        if(isPrint){
            cout << -1 << endl;
        }
        numberOfOperation --;
    }
    return 0;
}