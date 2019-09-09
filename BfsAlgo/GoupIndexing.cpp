#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

#define ROW 100
#define COL 100
struct Location{
    int y, x;
};

Location Destination;

int Direction[][2] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
};

void BFS(int matrix[][COL], bool visited[][COL]){
    queue<Location> queueForBfs;
    queueForBfs.push(Location{0, 0});
    visited[0][0] = true;

    int newRow, newCol;
    while(!queueForBfs.empty()){
        Location src = queueForBfs.front();
        queueForBfs.pop();
        visited[src.y][src.x] = true;

        for (int direction = 0; direction < 4; ++direction) {
            newRow = src.y + Direction[direction][0];
            newCol = src.x + Direction[direction][1];

            if(newRow < 0 || newRow >= Destination.y || newCol < 0 || newCol >= Destination.x){
                continue;
            }else{
                if(!visited[newRow][newCol] && matrix[newRow][newCol] != 0){
                    queueForBfs.push(Location{newRow, newCol});
                    matrix[newRow][newCol] = matrix[src.y][src.x] + 1;
                    visited[newRow][newCol] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio();
    cin >> Destination.y >> Destination.x;
    int matrix[ROW][COL] = {0};
    bool visited[ROW][COL] = {false};
    char temp[ROW+10][COL+10];

    for (int i = 0; i < Destination.y; ++i) {
        cin >> temp[i];
    }

    for (int i = 0; i < Destination.y; ++i) {
        for (int j = 0; j < Destination.x; ++j) {
            if(temp[i][j] == '1'){
                matrix[i][j] = 1;
            }else{
                matrix[i][j] = 0;
            }
        }
    }
    BFS(matrix, visited);
    cout << matrix[Destination.y - 1][Destination.x - 1];
    return 0;
}