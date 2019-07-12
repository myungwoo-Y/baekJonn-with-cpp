#include <iostream>
#include <vector>
#include "algorithm"
#include "math.h"

using namespace std;


void printStar(int n, char **arr, int row, int col){
    if(n == 3){
        for(int i = row; i < row + 3; i++){
            for(int j = col; j < col + 3; j++){
                arr[i][j] = '*';
            }
        }
        arr[row+1][col+1] = ' ';
    }else{
        n = n/3;
        for(int i = 0; i <  3; i++){
            for(int j = 0; j < 3; j++){
                if(i != 1 || j != 1){
                    printStar(n, arr, row+i*n, col+j*n);
                }
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char *arr[6600];
    for(int i = 0; i < 6600; i++){
        arr[i] = new char[6600];
    }

    for(int i = 0; i < 6600; i++){
        for(int j = 0; j < 6600; j++){
            arr[i][j] = ' ';
        }
    }
    printStar(n, arr, 0, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

