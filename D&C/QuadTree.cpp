#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

void search(int startRow, int startCol, int n, vector<vector<int>> arr){
    int cmp = arr[startRow][startCol];

    for (int i = startRow; i < startRow + n; ++i) {
        for (int j = startCol; j < startCol + n; ++j) {
            if(arr[i][j] != cmp){
                cout << "(";
                search(startRow, startCol, n/2, arr);
                search(startRow, startCol + n/2, n/2, arr);
                search(startRow + n/2, startCol, n/2, arr);
                search(startRow + n/2, startCol + n/2, n/2, arr);
                cout << ")";
                return;
            }
        }
    }
    cout << cmp;
}


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    char matrixValue;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrixValue;
            arr[i].push_back(matrixValue - '0');
        }
    }
    search(0, 0, n, arr);
    return 0;
}









