#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct Info{
    int row, col, size;
};


void search(vector<vector<int>>& table, int &white, int &blue, Info info){
    int compare = table[info.row][info.col];

    for (int i = info.row; i < info.row + info.size; ++i) {
        for (int j = info.col; j < info.col + info.size; ++j) {
            if(compare != table[i][j]){
                search(table, white, blue, Info({info.row, info.col, info.size/2}));
                search(table, white, blue, Info({info.row + info.size/2, info.col, info.size/2}));
                search(table, white, blue, Info({info.row, info.col + info.size/2, info.size/2}));
                search(table, white, blue, Info({info.row + info.size/2, info.col + info.size/2, info.size/2}));
                return;
            }
        }
    }

    if(compare == 1){
        blue ++;
    }else{
        white++;
    }

}

int main() {
    ios::sync_with_stdio(false);
    int n, inputInt;
    int white = 0, blue = 0;

    cin >> n;
    vector<vector<int>> table(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> inputInt;
            table[i].push_back(inputInt);
        }
    }

    search(table, white, blue, Info({0, 0, n}));

    cout << white << '\n' << blue;
    return 0;
}






