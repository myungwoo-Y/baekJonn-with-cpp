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


int goodSolution() {
    int n, a[1000], d[1000][2];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        d[i][0] = d[i][1] = 1;
    }
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j])
                d[i][0] = max(d[i][0], d[j][0] + 1);
            if (a[i] < a[j])
                // 나의 현재 최대 하강값, 비교수의 하강값과 나, 비교수의 증가값과 나
                d[i][1] = max(d[i][1], max(d[j][0] + 1, d[j][1] + 1));
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            ans = max(ans, d[i][j]);
    printf("%d", ans);
}
