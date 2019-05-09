#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void quickSort(int left, int right, vector<int>& arr){
    int start = left;
    int end = right;
    int pivot = arr[(left + right) / 2];
    do{
        while(arr[left] < pivot) left++;
        while(arr[right] > pivot) right--;
        if(left <= right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }while(left < right);

    if(start < right){
        quickSort(start, right, arr);
    }
    if(left < end){
        quickSort(left, end, arr);
    }
}

int average(vector<int> inputNumbers){
    int sum = 0;
    double average = 0;
    for(int index = 0; index < inputNumbers.size(); index++){
        sum += inputNumbers[index];
    }
    average =  double(sum) / inputNumbers.size();
    return round(average);
}

// 증앙값을 구하는 프로그램이다.
int middleValue(vector<int> inputNumbers){
    if((inputNumbers.size() % 2) != 0){
        return inputNumbers[inputNumbers.size() / 2];
    }else{
        int middleIndex = inputNumbers.size() / 2;
        double average = (double)(inputNumbers[middleIndex] + inputNumbers[middleIndex- 1]) / 2;
        return round(average);
    }
}

// 빈도수를 구한다. 빈도가 중복되면 두번쨰로 작은 값을 대표로 설정한다.
int frequence(vector<int> inputNumbers){
    int endElement = inputNumbers[inputNumbers.size() - 1];
    // for문에서 마지막 인덱스를 인식하지 않으므로 마지막 인덱스가 아닌 원소를 집어넣는다.
    inputNumbers.push_back(endElement + 1);

    // 빈도수가 많은 원소저장
    int manyFreqNum = inputNumbers[0];
    // 가장 큰 빈도수
    int maxFreq = 0;
    // 두번쨰로 큰 원소인지 확인하는 논리값
    int timeToChage = true;
    int count = 0;

    int size = inputNumbers.size();

    // index가 1부터 시작하므로 따로 0번째를 화인해준다.
    // 1부터 시작하는 이유는 timeToChange 를 true로 시작해야 for문이 작동하기 때문이다.
    if(inputNumbers[0] == inputNumbers[1] && size > 1){
        count ++;
    }


    // 1부터 시작하여 검사한다.
    for(int index = 1; index < size - 1; index++){

        // 중복되면 count 늘려준다.
        if(inputNumbers[index] == inputNumbers[index + 1]){
            count++;
        }else{
            // 중복되지 않으면 원소를 바꿔줄지 판단한다.
            // 더큰 중복 횟수를 가진 원소를 찾으면 단순히 집어넣어준다.
            if(maxFreq < count){
                maxFreq = count;
                manyFreqNum = inputNumbers[index];
                // 중복 횟수 같은 원소 찾으면 이 값이 두번째로 작은값이기 때문에 바로 넣을 수 있게한다.
                timeToChage = true;
            }else if(maxFreq == count){
                if(timeToChage){
                    // 중복 횟수가 같은 경우
                    // 두번째 작은 값이기 때문에 바로 현재 인댁스 값을 넣어준다.
                    manyFreqNum = inputNumbers[index];
                    // 다음 원소 저장을 원천 봉쇄한다.
                    timeToChage = false;
                }
            }
            count = 0;
        }
    }
    return manyFreqNum;

}

int range(vector<int> inputNumbers){
    if(inputNumbers.size() == 1){
        return 0;
    }
    return inputNumbers[inputNumbers.size() -1] - inputNumbers[0];
}


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> inputNumbers(n);

    for(int index = 0; index < inputNumbers.size(); index++){
        cin >> inputNumbers[index];
    }
    quickSort(0, inputNumbers.size() - 1, inputNumbers);

    cout << average(inputNumbers) << "\n";
    cout << middleValue(inputNumbers) << "\n";
    cout << frequence(inputNumbers) << "\n";
    cout << range(inputNumbers);

    return 0;
}