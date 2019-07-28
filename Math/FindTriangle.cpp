#include<cstdio>
#include<algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    int arr[3];
    bool isBreak;
    while(true){
        isBreak = true;
        for(int i = 0; i < 3; i++){
            scanf("%d", &arr[i]);
            if(arr[i] != 0){
                isBreak = false;
            }
        }
        if(isBreak) break;
        sort(arr, arr + 3);
        if(arr[0]*arr[0] + arr[1]*arr[1] == arr[2]*arr[2]){
            printf("right\n");
        }else{
            printf("wrong\n");
        }
    }
    return 0;
}