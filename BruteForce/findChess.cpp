#include<cstdio>
#include<algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int n,m;
char board[50][50];
int check(){
    char a[9][9] = {
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB"
    };

    char b[9][9] = {
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW"
    };
    int minCount = INT32_MAX;
    for (int i = 0; i <= n - 8; ++i) {
        for (int j = 0; j <= m - 8; ++j) {
            int startW = 0, startB = 0;
            for (int k = i; k < i+8; ++k) {
                for (int l = j; l < j+8; ++l) {
                    if(a[k-i][l-j] != board[k][l]){
                        startB++;
                    }

                    if(b[k-i][l-j] != board[k][l]){
                        startW++;
                    }
                }
            }
            minCount = min({minCount, startB, startW});
        }
    }
    return minCount;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &board[i][j]);
        }
    }

    printf("%d", check());

    return 0;
}
