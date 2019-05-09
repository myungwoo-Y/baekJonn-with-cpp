#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int directionAdd[][2] = {{-1, 0},
                         {0,  1},
                         {1,  0},
                         {0,  -1}};


struct Location{
    int x, y;
    void setLocation(int setX, int setY){
        x = setX;
        y = setY;
    }
};

void bts(Location startLocation, int** arr){
    int row, col;
    bool isVisit
    Location popLocation;
    queue<Location> q;
    q.push(startLocation);
    while(!q.empty()){
        popLocation = q.front();
        row = popLocation.x;
        col = popLocation.y;
        for(int i = 0; i < 4; i++){
            if(arr[row + directionAdd[i][0][col + directionAdd[i][1]]] == 1){

            }
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);

    int inputSize = 0;
    cin >> inputSize;

    int arr[inputSize][inputSize];

    for(int i = 0; i < inputSize; i++){
        for(int j = 0; j < inputSize; j++){
            cin >> arr[i][j];
        }
    }


    return 0;
}