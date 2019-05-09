//
// Created by myungwoo on 19. 2. 11.
//


#include <iostream>
using namespace std;


int findRule1(){
    int numberOfOperation;
    cin >> numberOfOperation;
    while(numberOfOperation > 0){
        long long x, y, distance, base, cnt;

        cin >> x >> y;
        distance = y - x;
        base = 1;
        cnt = 0;
        while(true){
            if(distance <= base){
                cnt++;
                break;
            }else{
                distance -= base*2;
                if(distance <= 0){
                    cnt += 2;
                    break;
                }
                base ++;
                cnt += 2;
            }
        }

        cout << cnt << endl;

        numberOfOperation --;
    }
    return 0;
}






