#include <iostream>
#include <vector>
#include "algorithm"
#include "math.h"
#include "ctime"
using namespace std;

int arr[1000];
int up[1001][2];
int down[1001][2];
int main() {
    int n, max = 0, u, d;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", arr + i);
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] < arr[j]){
                if(up[j][0] == 0){
                    up[j][0] = 1;
                    up[j][1] = i;
                }else if(arr[up[j][1]] < arr[i]){
                    up[j][0]++;
                    up[j][1] = i;
                }else if(arr[up[j][1]] > arr[i] && up[i][0] >= up[up[j][1]][0]){
                    up[j][1] = i;
                }
            }
        }
    }

    for(int i = n-1; i >= 1; i--){
        for(int j = i-1; j >= 0; j--){
            if(arr[i] < arr[j]){
                if(down[j][0] == 0){
                    down[j][0] = 1;
                    down[j][1] = i;
                }else if(arr[down[j][1]] < arr[i]){
                    down[j][0]++;
                    down[j][1] = i;
                }else if(arr[down[j][1]] > arr[i] && down[i][0] >= down[down[j][1]][0]){
                    down[j][1] = i;
                }
            }
        }
    }

    max = up[0][0] + down[0][0];
    for(int i = 1; i < n; i++){
        if(max < (up[i][0] + down[i][0])){
            max = up[i][0] + down[i][0];
        }
    }

    printf("%d", max + 1);

    return 0;
}
