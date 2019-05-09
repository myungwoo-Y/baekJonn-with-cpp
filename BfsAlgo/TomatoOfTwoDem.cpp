#include <iostream>
#include <bits/stdc++.h>
#include "queue"

using namespace std;
// 죄표를 저장 할 자료구조이다.
typedef pair<int, int> P;
int row, col;

int BFS(queue<P> &queue, int **arr) {
    // 몇번의 bfs가 이루어졌는지 카운트
    int bfsCount = 0;
    
    // 원소들을 더하면 방향 이동을 가능하게한다.
    // 위, 왼쪽, 아래, 오른쪽 순으로 순서했다.
    int directionAdd[][2] = {{-1, 0},
                             {0,  1},
                             {1,  0},
                             {0,  -1}};

    // 큐가 모두 빌떄까지 반복한다.
    while (queue.size() != 0) {
        int queueSize = queue.size();
        for (int i = 0; i < queueSize; i++) {
            P visitedIndex = queue.front();
            queue.pop();
            for (int direction = 0; direction < 4; direction++) {
                P movedIndex;
                movedIndex = {visitedIndex.first + directionAdd[direction][0],
                              visitedIndex.second + directionAdd[direction][1]};
                if (movedIndex.first < 0 || movedIndex.first >= row || movedIndex.second < 0 ||
                    movedIndex.second >= col) {
                    continue;
                } else if (arr[movedIndex.first][movedIndex.second] == 0) {
                    arr[movedIndex.first][movedIndex.second] = 1;
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
    cin >> col >> row;
    
    //매개변수를 더블 포인터로 만들기 위해 수정한것이다. 
    int **arr = new int *[row]; // row 할당
    // col 할당
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }
    // 다른 토마토들을 익혀줄 토마토들의 좌표들
    pair<int, int> startPoints[row * col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
            // 1이면 startPoint에 넣어준다.
            if (arr[i][j] == 1) {
                startPoints[numberOfStartPoint] = {i, j};
                numberOfStartPoint++;
            // -1이면 벽이기 때문에 추가해준다.
            } else if (arr[i][j] == -1) {
                numberOfWall++;
            }
        }
    }
    // 모두 익어있는지 확인
    if (((row * col) - numberOfWall) == numberOfStartPoint) {
        mostDate = 0;
    } else {
        queue<P> queue;
        // bfs 시작점들을 큐에 넣어준다.
        for (int i = 0; i < numberOfStartPoint; i++) {
            queue.push(startPoints[i]);
        }

        // BFS의 연산 횟수가 곧 익기 위해 필요한 날짜이다.
        mostDate = BFS(queue, arr) - 1;

        // 안익은 토마토가 있는지 검사한다.
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(arr[i][j] == 0){
                    mostDate = -1;
                    break;
                }
            }
        }
    }
    cout << mostDate;
    return 0;
}