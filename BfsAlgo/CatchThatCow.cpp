#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int visited[200001];
struct Location{
    int x, count;
};

int BFS(int src, int dest) {
    queue<Location> queueBfs;
    queueBfs.push(Location({src, 0}));
    Location currentLocation, nextLocation;
    int minCount = abs(dest - src);
    while (!queueBfs.empty()){
        currentLocation = queueBfs.front();
        queueBfs.pop();
        int currentX = currentLocation.x;
        int currentCount = currentLocation.count;
        if(currentX <= 200000 && currentCount < minCount && currentX >= 0 && (!visited[currentX] || (currentCount < visited[currentX]))){
            visited[currentX] = currentCount;
            if(currentX == dest){
                minCount = currentCount;
            }
            queueBfs.push(Location({currentX+1, currentCount+1}));
            queueBfs.push(Location({currentX-1, currentCount+1}));
            queueBfs.push(Location({currentX*2, currentCount+1}));
        }
    }
    return minCount;
}

int main() {
    ios_base::sync_with_stdio();
    int src, dest;
    cin >> src >> dest;
    cout << BFS(src, dest);

    return 0;
}






