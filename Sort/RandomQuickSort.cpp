#include <iostream>
#include <time.h>

using namespace std;

void swapElement(int firstIndex, int secondIndex, int arr[]){
    int elementTemp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = elementTemp;
}


void quickSort(int left, int right, int arr[]){
    srand(time(NULL));
    int pivotIndex = rand() % (right - left + 1) + left;
    int pivot = arr[pivotIndex];
    int start = left;
    int end = right;

    do{
        while(arr[left] < pivot) left ++;
        while(arr[right] > pivot) right --;
        if(left <= right){  // left == right 일 경우에 각각 값을 1씩 변
            swapElement(left, right, arr);
            left++;
            right--;
        }
    }while(left < right);

    if(start < right)
        quickSort(start, right, arr);
    if(left < end)
        quickSort(left, end, arr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[10000];
    int size = 0;
    cin >> size;

    for(int index = 0 ; index < size; index++){
        cin >> arr[index];
    }

    quickSort(0, size - 1, arr);

    for(int index = 0 ; index < size; index++){
        cout << arr[index] << " ";
    }

    return 0;
}