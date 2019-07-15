#include<cstdio>
#include<algorithm>
#include <ctime>
#include <queue>
#include <cstring>

using namespace std;
int n ,m, map[500][500], dp[500][500];
int direction[4][2] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
};

int dfs(int x, int y){

    int nx, ny, sum = 0;


    if(x == n-1 && y == m-1){
        dp[x][y] = 1;
        return 1;
    }

    if(dp[x][y] != -1){
        return dp[x][y];
    }

    dp[x][y] = 0;
    for(int i = 0; i < 4; i++){
        nx = x + direction[i][0];
        ny = y + direction[i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m
           || map[nx][ny] >= map[x][y]){
            continue;
        }
        dp[x][y] += dfs(nx, ny);
    }

    return dp[x][y] ;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));

    printf("%d", dfs(0, 0));

    return 0;
}