#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <time.h>
#include <iterator>

using namespace std;

int arr[1000001];
int aux[1000001];
long long int numberOfset;

void merge(int start, int mid, int end){
    if(start == end){
        return;
    }

    int left = start, right = mid+1;
    int inPoint = left;

    int compareStart = left;
    for (int i = right; i <= end; ++i) {
        for (int j = compareStart; j <= mid ; ++j) {
            if(arr[j] > arr[i]){
                numberOfset += mid - j + 1;
                compareStart = j;
                break;
            }
        }
    }

    while(left <= mid && right <= end){
        if(arr[left] < arr[right]){
            aux[inPoint++] = arr[left++];
        }else{
            aux[inPoint++] = arr[right++];
        }
    }

    while (left <= mid){
        aux[inPoint++] = arr[lnneft++];
    }

    copy(begin(aux) + start, begin(aux) + end + 1, begin(arr) + start);
}

void mergeSort(int start, int end){
    if(start == end){
        return;
    }

    int mid = ((end + start) >> 1);

    mergeSort(start, mid);
    mergeSort(mid+1, end);
    merge(start, mid, end);
}

int main() {
    ios_base::sync_with_stdio(false);

    srand(time(NULL));
    int n;
    cin >> n;
//    n = 1000000;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        aux[i] = arr[i];
    }

    mergeSort(0, n-1);
    cout << numberOfset;
    return 0;
}









