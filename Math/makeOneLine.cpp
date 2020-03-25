/*
    백준 1138번
    한줄로 서기
 */

#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define LOCAL
using namespace std;

static string endL = "\n";

int n {0};

bool checkAllSelect(vector<bool>& isVisit){
    for (int i = 1; i <= n; ++i) {
        if(!isVisit.at(i)) return false;
    }
    return true;
}

bool search(int curHeight, vector<int> leftCounts, vector<bool> isVisit, vector<int> lines){
    // 기존 리스트의 키를 나보다 작으면 카운트에서 차감
    for (int i = 1; i < lines.size(); i++) {
        int addedHeight = lines[i];
        if(curHeight > addedHeight){
            leftCounts[addedHeight]--;
            if(leftCounts[addedHeight] < 0){
                return false;
            }
        }
    }

    lines.push_back(curHeight);
    isVisit[curHeight] = true;

    if(checkAllSelect(isVisit)){
        for (int i = n; i >= 1; --i) {
            cout << lines[i] << " ";
        }
        return true;
    }


    for (int h = 1; h <= n; ++h) {
        if(!isVisit[h]){
            if(search(h, leftCounts, isVisit, lines)){
                lines.pop_back();
                return true;
            }
        }
    }

    return false;

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
//        freopen("in.txt", "r", stdin);
    #endif

    cin >> n;
    vector<int> leftCounts(n+1);

    for (int i = 1; i <= n; ++i) {
        cin >> leftCounts[i];
    }

    vector<bool> isVisit(n+1);

    for (int i = 1; i <= n; ++i) {
        if(search(i, leftCounts, isVisit, vector<int>(1))){
            break;
        }
    }







    return 0;
}