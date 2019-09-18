#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <queue>
#define MAX_ROW 1000
#define MAX_COL 1000
#define VALUE 0
#define NOT_WALL 1
#define WALL 2

int table[MAX_ROW][MAX_COL][3];
using namespace std;

struct Location{
    int y, x, visit;
};

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int BFS(int row, int col){
    queue<Location> queueLocation;
    queueLocation.push(Location({0, 0, NOT_WALL}));
    table[0][0][NOT_WALL] = 1;
    int nextRow, nextCol ;
    while (!queueLocation.empty()){
        Location currentLocation = queueLocation.front();
        queueLocation.pop();
        int currentRow = currentLocation.y;
        int currentCol = currentLocation.x;
        int visit= currentLocation.visit;
        for (int direction = 0; direction < 4; ++direction) {
            nextRow = currentRow + dy[direction];
            nextCol = currentCol + dx[direction];
            if(nextRow < 0 || nextRow >= row || nextCol < 0 || nextCol >= col){
                continue;
            }

            if(table[nextRow][nextCol][visit]){
                continue;
            }

            if(table[nextRow][nextCol][VALUE] == 0){
                table[nextRow][nextCol][visit] = table[currentRow][currentCol][visit] + 1;
                queueLocation.push(Location({nextRow, nextCol, visit}));
            }else if(table[nextRow][nextCol][VALUE] == 1 && visit == NOT_WALL){
                table[nextRow][nextCol][WALL] = table[currentRow][currentCol][visit] + 1;
                queueLocation.push(Location({nextRow, nextCol, WALL}));
            }
        }
    }
    int minValue = min(table[row-1][col-1][NOT_WALL], table[row-1][col-1][WALL]);
    int maxValue = max(table[row-1][col-1][NOT_WALL], table[row-1][col-1][WALL]);
    if(maxValue == 0 && maxValue == 0){
        return -1;
    }else if(minValue == 0){
        return maxValue;
    }else{
        return minValue;
    }
}

int main() {
    ios_base::sync_with_stdio();

    int row , col;

    cin >> row >> col;
    char temp;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> temp;
            table[i][j][VALUE] = temp - '0';
        }
    }
    cout << BFS(row, col);

    return 0;
}






