#include <iostream>
#include <vector>
#include "algorithm"
#include "math.h"

using namespace std;



int main() {
    char arr[100][100];

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            arr[i][j] = '.';
        }
    }
    char word[16], symbol = '#';
    int row = 2, col = 2;

    scanf("%s", word);
    for(int i = 0; word[i]; i++){
        arr[row][col] = word[i];
        if((i+1) % 3 == 0){
            symbol = '*';
        }
        for(int k = -2; k <= 2; k++){
            for(int u = -2; u <= 2; u++){
                if(abs(k) + abs(u) == 2){
                    if(arr[row+k][col+u] == '*'){
                        continue;
                    }
                    arr[row+k][col+u] = symbol;
                }
            }
        }
        symbol = '#';
        col += 4;
    }
    for(int i = 0; i <= row+2; i++){
        for(int j = 0; j <= col-2; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

