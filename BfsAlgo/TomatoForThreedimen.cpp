#include <iostream>
#include <bits/stdc++.h>
#include "queue"

using namespace std;
typedef pair<int, int> P;


struct Location{
    void setValue(int inputX, int inputY, int inputZ){
        x = inputX;
        y = inputY;
        z = inputZ;
    }
    int x, y, z;
};

int row, col, depth;

int BFS(queue<Location> &queue, int ***arr) {

    int bfsCount = 0;
    int directionAdd[][3] = {{-1, 0, 0},
                             {1, 0, 0},
                             {0, -1, 0},
                             {0, 1,  0},
                             {0, 0, -1},
                             {0, 0, 1}};


    while (queue.size() != 0) {
        int queueSize = queue.size();
        for (int i = 0; i < queueSize; i++) {
            Location visitedIndex = queue.front();
            queue.pop();
            for (int direction = 0; direction < 6; direction++) {
                Location movedIndex;
                movedIndex = {visitedIndex.x + directionAdd[direction][0],
                              visitedIndex.y + directionAdd[direction][1],
                              visitedIndex.z + directionAdd[direction][2]};
                if (movedIndex.x < 0 || movedIndex.x >= row || movedIndex.y < 0 ||
                    movedIndex.y >= col || movedIndex.z < 0 || movedIndex.z >= depth)  {
                    continue;
                } else if (arr[movedIndex.z][movedIndex.x][movedIndex.y] == 0){
                    arr[movedIndex.z][movedIndex.x][movedIndex.y] = 1;
                    queue.push(movedIndex);
                }
            }
        }

        bfsCount++;
    }
    return bfsCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    int numberOfStartPoint = 0;
    int numberOfWall = 0;
    int mostDate = 0;
    cin >> col >> row >> depth;

    // 3차원 배열을 생성한다.
    int ***arr = new int **[depth];
    for (int i = 0; i < depth; i++) {
        arr[i] = new int *[row];
        for(int j = 0; j < row; j++){
            arr[i][j] = new int[col];
        }
    }

    Location startPoints[row * col * depth];
    for (int d = 0; d < depth; d++) {
        for (int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++){
                cin >> arr[d][r][c];
                if (arr[d][r][c] == 1) {
                    startPoints[numberOfStartPoint].setValue(r, c, d);
                    numberOfStartPoint++;
                } else if (arr[d][r][c] == -1) {
                    numberOfWall++;
                }
            }
        }
    }
    if (((row * col * depth) - numberOfWall) == numberOfStartPoint) {
        mostDate = 0;
    } else {
        queue<Location> queue;
        for (int i = 0; i < numberOfStartPoint; i++) {
            queue.push(startPoints[i]);
        }

        mostDate = BFS(queue, arr) - 1;

        for (int d = 0; d < depth; d++) {
            for (int r = 0; r < row; r++) {
                for (int c = 0; c < col; c++) {
                    if (arr[d][r][c] == 0) {
                        mostDate = -1;
                        break;
                    }
                }
            }
        }
    }
    cout << mostDate;
    return 0;
}