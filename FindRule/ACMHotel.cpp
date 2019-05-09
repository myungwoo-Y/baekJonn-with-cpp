//
// Created by myungwoo on 19. 2. 11.
//

#include <iostream>
using namespace std;
int acmHotel(){
    int numberOfOperation;
    cin >> numberOfOperation;
    int currentRow, currentColumn;
    while(numberOfOperation > 0){
        int maxRow, maxColumn, people;
        cin >> maxRow >> maxColumn >> people;
        currentRow = 0 , currentColumn = 1;
        for(int i = 0; i < people; i++){
            currentRow ++;
            if(currentRow > maxRow){
                currentRow = 1;
                currentColumn ++;
            }
        }
        numberOfOperation--;
        if(currentColumn > 9){
            cout << currentRow << currentColumn << endl;
        }else{
            cout << currentRow << "0" << currentColumn << endl;
        }
    }
    return 0;
}





