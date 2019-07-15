#include<cstdio>
#include<algorithm>
#include <ctime>

using namespace std;

int lowerBound(int size, int value, int arr[]){
    int start = 0, end = size-1;
    while(start < end){
        if(arr[(start + end) / 2] == value){
            return (start + end) / 2;
        }else if(arr[(start + end) / 2] > value){
            end = (start + end) / 2;
        }else{
            start = (start + end) / 2 + 1;
        }
    }

    return start;
}

int main() {
    int n, a[40000], dp[40000], dpSize = 0, slowDp[40000];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++){
        if(dpSize == 0){
            dp[dpSize++] = a[i];
        }else if(dp[dpSize-1] < a[i]){
            dp[dpSize] = a[i];
            ++dpSize;
        }else{
            dp[lowerBound(dpSize, a[i], dp)] = a[i];
        }
    }

    printf("%d", dpSize);

    return 0;
}