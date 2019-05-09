//
// Created by myungwoo on 19. 2. 9.
//

#include <iostream>
using namespace std;

int NumberOfPeople(){
    int numberOfPrint;
    int k;
    int n;
    int floors[15][15];
    for(int row = 0; row <= 14; row++){
        for(int col = 1; col <= 14; col++){
            if(row == 0){
                floors[row][col] = col;
            } else if(col == 1){
                floors[row][col] = 1;
            } else{
                floors[row][col] = floors[row][col-1] + floors[row-1][col];
            }
        }
    }

    cin >> numberOfPrint;
    for(int i = 0; i < numberOfPrint; i++){
        cin >> k >> n;
        cout << floors[k][n] << endl;
    }
    return 0;
}







