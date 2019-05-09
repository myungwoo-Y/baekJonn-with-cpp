#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int g_row, g_col;
bool g_isRule = true;
void matrixSearch(int numberOfSquare, int row, int col, unsigned int& cnt) {
    // 찾는 수에 도달했는지 확인
    if(row == g_row &&col == g_col){
        return;
    }
    // z 모양일 경우
    if(g_isRule){
        int addIndex = pow(2, numberOfSquare - 1);
        g_isRule = !g_isRule;
        // 가운데를 잘라준다.
        if(g_row >= row + addIndex){
            cnt += pow(2, (numberOfSquare * 2 ) - 1);
            return matrixSearch(numberOfSquare - 1, row + addIndex, col, cnt);
        }else{
            return matrixSearch(numberOfSquare - 1, row, col, cnt);
        }

        // 범위가 z 모양이 아닐 경우
    }else{
        g_isRule = !g_isRule;
        int addIndex = pow(2, numberOfSquare);
        // 가운데를 잘라준다.
        if(g_col >= col + addIndex){
            cnt += pow(2, (numberOfSquare * 2));
            return matrixSearch(numberOfSquare, row, col  + addIndex, cnt);
        }else{
            return matrixSearch(numberOfSquare, row , col, cnt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int numberOfSquare;
    unsigned int u_cnt;
    while(cin >> numberOfSquare >> g_row >> g_col){
        g_isRule = true;
        u_cnt = 0;
        matrixSearch(numberOfSquare, 0, 0, u_cnt);
        cout << u_cnt << "\n";
    }

    return 0;
}