/*
 * 종만북 시계 맞추기
 */
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

#define LOCAL
#define VII vector<vector<int>>
#define VDD vector<vector<double>>
#define VCC vector<vector<char>>
#define VI vector<int>
#define VB vector<bool>
#define VS vector<<string>
#define VC vector<char>
#define VD vector<double>
#define loop(n) for(int x = 0; x < n; ++x)

using namespace std;

const string endL = "\n";

int switchN {10}, clockN {16}, switchMax {3}, increase {3}, targetClock {0};

void increaseClocks(int switchIdx, VI& clocks, VI& switchCnts, VII& switchs){
    switchCnts[switchIdx]++;
    VI swt = switchs[switchIdx];
    for (auto targetC : swt) {
        clocks[targetC] += increase;
    }
}

void decreaseClocks(int switchIdx, VI& clocks, VI& switchCnts, VII& switchs){
    switchCnts[switchIdx]--;
    VI swt = switchs[switchIdx];
    for (auto targetC : swt) {
        clocks[targetC] -= increase;
    }
}

int countSwitchCnt(VI& switchCnts){
    int sum {0};
    for(auto cnt : switchCnts) {
        sum += cnt;
    }
    return sum;
}

bool isAllMax(VI& switchCnts){
    for(auto cnt : switchCnts){
        if(cnt != switchMax) return false;
    }
    return true;
}

bool isAllClockSame(VI& clocks){
    for(auto clock : clocks){
        if((clock % 12) != targetClock){
            return false;
        }
    }
    return true;
}

int search(int cur, VI& clocks, VII& switchs, VI& switchCnts, int& count){
    if(switchCnts[0] == 0
       && switchCnts[1] == 0
       && switchCnts[2] == 0
       && switchCnts[3] == 0
       && switchCnts[4] == 0
       && switchCnts[5] == 0
       && switchCnts[6] == 0
       && switchCnts[7] == 0
       && switchCnts[8] == 2){
//        cout << 1;
    }

    if(isAllClockSame(clocks)){
        return countSwitchCnt(switchCnts);
    }

    if(isAllMax(switchCnts)) return INT32_MAX;

    int sumCnt {INT32_MAX};
    for (int swtichIdx = cur; swtichIdx < switchN; ++swtichIdx) {
        if(switchCnts[swtichIdx] != switchMax){
            increaseClocks(swtichIdx, clocks, switchCnts, switchs);
            ++count;
            sumCnt = min(search(swtichIdx, clocks, switchs, switchCnts, count), sumCnt);
            decreaseClocks(swtichIdx, clocks, switchCnts, switchs);
        }
    }
    return sumCnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
//        freopen("in.txt", "r", stdin);
#endif

    VII switchs(switchN);

    switchs[0] = VI{0, 1, 2};
    switchs[1] = VI{3, 7, 9, 11};
    switchs[2] = VI{4, 10, 14, 15};
    switchs[3] = VI{0, 4, 5, 6, 7};
    switchs[4] = VI{6, 7, 8, 10, 12};
    switchs[5] = VI{0, 2, 14, 15};
    switchs[6] = VI{3, 14, 15};
    switchs[7] = VI{4, 5, 7, 14, 15};
    switchs[8] = VI{1, 2, 3, 4, 5};
    switchs[9] = VI{3, 4, 5, 9, 13};

    int testCase {};

    cin >> testCase;
    int a {};
    loop(testCase){
        VI clocks(clockN);
        VI switchCnts(switchN);
        for (int i = 0; i < clockN; ++i) {
            cin >> clocks[i];
        }
        int count = search(0, clocks, switchs, switchCnts, count);
        if(count == INT32_MAX){
            cout << -1 << endL;
        }else{
            cout << count << endL;
        }
    }



    return 0;
}