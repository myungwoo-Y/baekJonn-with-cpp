#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    int n, h, minCount = INT8_MAX;
    int arr[200001];
    cin >> n >> h;
    int duplicate = 1;
    int upValues[500000] = {0};
    int downVaules[500000] = {0};

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }


    // 장애물에 영향 받는 기준 인덱스에 값을 추가해준다.
    for (int i = 1; i <= n; i += 2) {
        upValues[arr[i]]++;
        downVaules[h - arr[i + 1] + 1]++;
    }

    // 구해준 값들을 모두 더해준다.
    for (int i = 2; i <= h; i++) {
        upValues[h - i] += upValues[h - i + 1];
        downVaules[i] += downVaules[i - 1];
    }

    int minNumber = upValues[1] + downVaules[1];

    // 중복있는지 검사하고 최솟값을 찾는다.
    for(int i = 2; i <= h; i++){
        if(minNumber == upValues[i] + downVaules[i]){
            duplicate++;
        }else if(minNumber > upValues[i] + downVaules[i]){
            duplicate = 1;
            minNumber = upValues[i] + downVaules[i];
        }
    }


    cout << minNumber << " " << duplicate;





    return 0;
}