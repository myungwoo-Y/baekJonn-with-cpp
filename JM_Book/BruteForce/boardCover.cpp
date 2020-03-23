#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static string End = "\n";

struct Point{
    int r, c;
};

vector<vector<Point>> dir(4);

bool indexCheck(int r, int c, int rowS, int colS){
    return !(r < 0 || r >= rowS || c < 0 || c >= colS);
}

void restoreTable(int r, int c, vector<Point>& p, vector<vector<char>>& table){
    for(auto point: p){
        table[r+point.r][c+point.c] = '.';
    }
}

void markTable(int r, int c, vector<Point>& p, vector<vector<char>>& table){
    for(auto point: p){
        table[r+point.r][c+point.c] = '#';
    }
}

bool checkDirection(int r, int c, vector<Point>& p, vector<vector<char>>& table){
    for(auto point: p){
        int newR = r+point.r, newC = c+point.c;
        if(!indexCheck(newR, newC, table.size(), table[0].size())){
            return false;
        }else{
            if(table[newR][newC] ==  '#'){
                return false;
            }
        }
    }
    return true;
}

int solve(vector<vector<char>>& table){
    int row {-1}, col {-1};

    // 위에서부터 빈곳이 있는지 확인한다.
    for (int i = 0; i < table.size(); ++i) {
        for (int j = 0; j < table[0].size(); ++j) {
            if(table[i][j] == '.'){
                row = i;
                col = j;
                i = table.size();
                break;
            }
        }
    }

    // 기저사례이다.
    if(row == -1){
        return 1;
    }
    int count {0};
    for (auto points : dir) {
        if(checkDirection(row, col, points, table)){
            markTable(row, col, points, table);
            count += solve(table);
            restoreTable(row, col, points, table);
        }
    }
    return count;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase {0};
    cin >> testCase;

    dir[0] = {{0,0}, {1, 0}, {0, 1}};
    dir[1] = {{0,0}, {0, 1}, {1, 1}};
    dir[2] = {{0,0}, {1, 0}, {1, 1}};
    dir[3] = {{0,0}, {1, 0}, {1, -1}};


    for (;testCase > 0 ; --testCase) {
        int row {0}, col {0};
        cin >> row >> col;
        vector<vector<char>> table(row);
        for (int i = 0; i < row; ++i) {
            table[i].resize(col);
            for (int j = 0; j < col; ++j) {
                cin >> table[i][j];
            }
        }
        cout << solve(table) << End;
    }


    return 0;
}