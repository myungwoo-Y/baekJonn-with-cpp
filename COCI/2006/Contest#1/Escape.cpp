#include <iostream>
#include <vector>
#include "algorithm"
#include "math.h"
#include "queue"

using namespace std;

struct Location {
    int x, y;

    void setLocation(int inputX, int inputY) {
        x = inputX;
        y = inputY;
    }
};

int arr[50][50][2];
Location start;
Location destination;
Location waters[2500];
int waterSize = 0, maxRow, maxCol;

void waterDfs(int row, int col, int visitCount) {
    if(row < 0 || col < 0 || row >= maxRow || col >= maxCol){
        return;
    }

    if(arr[row][col][0] == 'X' ||
       arr[row][col][0] == 'D' ||
       arr[row][col][0] == 'S') {
        return;
    }

    if(arr[row][col][1] > visitCount){
        arr[row][col][1] = visitCount;
        waterDfs(row+1, col, visitCount+1);
        waterDfs(row, col+1, visitCount+1);
        waterDfs(row-1, col, visitCount+1);
        waterDfs(row, col-1, visitCount+1);
    }else{
        return;
    }
}

void watersSearch() {
    Location water;
    for (; waterSize > 0; waterSize--) {
        water = waters[waterSize - 1];
        waterDfs(water.x, water.y, 0);
    }
}


void startDfs(int row, int col, int visitCount){
    if(row < 0 || col < 0 || row >= maxRow || col >= maxCol){
        return;
    }

    if(arr[row][col][0] == 'X' ||
       arr[row][col][0] == '*') {
        return;
    }


    if(arr[row][col][1] > visitCount){
        arr[row][col][1] = visitCount;
        startDfs(row+1, col, visitCount+1);
        startDfs(row, col+1, visitCount+1);
        startDfs(row-1, col, visitCount+1);
        startDfs(row, col-1, visitCount+1);
    }else{
        return;
    }
}

int main() {
    char temp[52];
    scanf("%d %d", &maxRow, &maxCol);
    for (int i = 0; i < maxRow; i++) {
        scanf("%s", temp);
        for (int j = 0; temp[j]; j++) {
            arr[i][j][0] = temp[j];
            if (temp[j] == 'D') {
                destination.setLocation(i, j);
            } else if (temp[j] == '*') {
                waters[waterSize++].setLocation(i, j);
            } else if (temp[j] == 'S') {
                start.setLocation(i, j);
            }
        }
    }
    for(int i = 0; i < maxRow; i++){
        for(int j = 0; j < maxCol; j++){
            arr[i][j][1] = INT32_MAX;
        }
    }

    watersSearch();



    arr[destination.x][destination.y][1] = INT32_MAX;

    startDfs(start.x, start.y, 0);

//
//    for(int i = 0; i < maxRow; i++){
//        for(int j = 0; j < maxCol; j++){
//            printf("%d ", arr[i][j][1]);
//        }
//        printf("\n");
//    }

    if(arr[destination.x][destination.y][1] == INT32_MAX){
        printf("KAKTUS");
    }else{
        printf("%d", arr[destination.x][destination.y][1]);
    }
    return 0;
}

