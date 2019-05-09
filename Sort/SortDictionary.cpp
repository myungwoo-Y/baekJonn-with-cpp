#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void quickSort(int left, int right, vector<string>& inputStrings){
    int start = left;
    int end = right;
    int pivot = inputStrings[(left + right) / 2].size();
    do{
        while(inputStrings[left].size() < pivot) left++;
        while(inputStrings[right].size() > pivot) right--;
        if(left <= right){
            string temp = inputStrings[left];
            inputStrings[left] = inputStrings[right];
            inputStrings[right] = temp;
            left++;
            right--;
        }
    }while(left < right);
    if(start < right)
        quickSort(start, right, inputStrings);
    if(left < end)
        quickSort(left, end, inputStrings);

}


void countingSort(vector<string>& inputStrings, int indexOfString){  // 자릿수(indexOfString)를 기준으로 정렬한다.
    vector<string> newString(inputStrings.size());  // 정렬된 원소를 집어넣을 배열이다.
    int size = inputStrings.size();
    int alphaCount[31];   // 각 알파벳에 대해 값을 증가시킨다.
    fill_n(alphaCount, 31, 0);  // 값을 초기화 시킨다.

    for(int index = 0; index < size; index++){  // count 를 한다.
        if(inputStrings.at(index).size() < indexOfString){
            alphaCount[0]++;  // 해당 자릿수에 원소가 없을때 인덱스 0에 집어 넣어 최우선으로 한다.
        }else{
            string stringAtInput = inputStrings[index];  // 원소가 있을 경우 해당 원소 값에 해당하는 자리에 값을 집어넣는다.
            alphaCount[stringAtInput.at(indexOfString - 1) - 'a' + 1]++;
        }
    }

    for(int index = 1; index < 31; index++){  // count 한 것들을 모두 합쳐준다.
        alphaCount[index] += alphaCount[index-1];
    }

    for(int index = size - 1; index >= 0; index--){  // 원소를 제자리에 집어넣는다.
        if(inputStrings[index].size() < indexOfString){  // 해당 자리에 원소 없을 경우 0에 해당하는 값에 따른 자리에 집어넣는다.
            newString[alphaCount[0] - 1] = inputStrings[index];
            alphaCount[0]--;
        }else{
            string stringAtInput = inputStrings[index];  // 원소가 있다면 자리에 해당하는 곳에 원소 집어넣는다.
            int alphaIndex = stringAtInput.at(indexOfString - 1) - 'a' + 1;
            newString[alphaCount[alphaIndex] - 1] = inputStrings[index];
            alphaCount[alphaIndex] --;
        }
    }

    inputStrings = newString;
}

// 최댓값 사이즈를 반환한다.
int getMax(vector<string> findMaxString){
    int size = findMaxString[0].size();
    for(int index = 1; index < findMaxString.size(); index++){
        if(size < findMaxString[index].size()){
            size = findMaxString[index].size();
        }
    }
    return size;
}

// 원소 길이에 따라 정렬한다. 퀵소트는 불안전 정렬이기 떄문에 counting sort 를 사용한다.
void countingSortForLength(vector<string>& inputStrings){
    vector<string> newString(inputStrings.size());
    int size = inputStrings.size();
    int maxSize = getMax(inputStrings);
    int lengthCount[maxSize+1];
    fill_n(lengthCount, maxSize+1, 0);

    for(int index = 0; index < size; index++){
        lengthCount[inputStrings[index].size()]++;
    }

    for(int index = 1; index <= maxSize; index++){
        lengthCount[index] += lengthCount[index-1];
    }

    for(int index = size - 1; index >= 0; index--){
        int targetIndex = lengthCount[inputStrings[index].size()] - 1;
        newString[targetIndex] = inputStrings[index];
        lengthCount[inputStrings[index].size()]--;
    }

    inputStrings = newString;
}

// 중복을 제거하는 함수이다,
void removeDuplicate(vector<string>& inputStrings){
    int index = 1;
    while(index < inputStrings.size()){
        if(inputStrings[index] == inputStrings[index-1]){
            inputStrings.erase(inputStrings.begin()+index);
            index--;
        }
        index++;
    }
}



int main() {
    int n;
    int alpha[30];
    cin >> n;
    vector<string> inputStrings(n);

    for(int index = 0; index < n; index++){
        cin >> inputStrings[index];
    }

    int maxSize = getMax(inputStrings);

    // 각 자릿수 만큼 counting sort 하여 사전 순으로 정렬되게 한다.
    for(int digit = maxSize; digit > 0; digit--){
        countingSort(inputStrings, digit);
    }

    // 중복을 제거한다.
    removeDuplicate(inputStrings);

    // 사전순으로 정렬돼있는 원소들을 다시 길이 순으로 정렬한다.
    countingSortForLength(inputStrings);

    for(int index = 0; index < inputStrings.size(); index++){
        cout << inputStrings[index] << "\n";
    }


    return 0;
}