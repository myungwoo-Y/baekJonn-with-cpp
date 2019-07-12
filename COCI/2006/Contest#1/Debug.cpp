#include <iostream>
#include <vector>
#include "algorithm"
#include "math.h"

using namespace std;

int searchKiller(int n, int row, int col, int arr[301][301]) {
    int limitR, limitC;
    bool isKiller;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i + n > row || j + n > col) {
                continue;
            }
            if (n % 2 != 0) {
                limitR = n / 2 + i;
                limitC = n / 2 + j;
            } else {
                limitR = n - 1 + i;
                limitC = n / 2 - 1 + j;
            }
            isKiller = true;

            for (int c = j; c <= limitC; c++) {
                for (int r = i; r < i + n ; r++) {
                    if (i == 21 && j == 23 && n == 114) {
                        int k = 1;
                    }
                    int a = n - r - 1 + 2 * i;
                    int b = n - c - 1 + 2 * j;
                    if (arr[r][c] != arr[a][b]) {
                        r = i + n;
                        c = limitC + 1;
                        isKiller = false;
                    }
                }
            }
            if (isKiller) {
                printf("%d", n);
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int row, col;
    char temp[301];
    int arr[301][301];
    scanf("%d %d", &row, &col);
    for (int i = 0; i < row; i++) {
        scanf("%s", temp);
        for (int j = 0; j < col; j++) {
            arr[i][j] = temp[j] - '0';
        }
    }

    for (int i = min(row, col); i > 0; i--) {
        if (searchKiller(i, row, col, arr) == 1) {
            return 0;
        }

    }

    printf("-1");

    return 0;
}

