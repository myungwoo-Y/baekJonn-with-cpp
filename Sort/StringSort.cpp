#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swapElement(int a, int b, char arr[]){
    char temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void sort(int left, int right, char arr[]){
    int start = left;
    int end = right;
    char pivot = arr[(left + right) / 2];

    do{
        while(arr[left] > pivot) left++;
        while(arr[right] < pivot) right--;
        if(left <= right){
            swapElement(left, right, arr);
            left++;
            right--;
        }
    }while(left < right);

    if(start < right)
        sort(start, right, arr);
    if(end > left)
        sort(left, end, arr);
}

int main() {
    char arr[1000];
    cin >> arr;
    int size;
    for(size = 0; arr[size]; size++);
    sort(0, size-1, arr);
    cout << arr;

    return 0;
}