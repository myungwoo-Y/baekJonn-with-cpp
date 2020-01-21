#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Point{
    int x,y;
    Point(int _y, int _x){
        x = _x;
        y = _y;
    }
};

int n;

int findQueen(int startRow, int startCol, int count, vector<Point> selectPoint){
    if(count == n){
        return 1;
    }

    int sum {0};
    bool canPut;
    for (int r = startRow; r < n; ++r) {
        if(r != startRow){
            startCol = 0;
        }
        for (int c = startCol; c < n; ++c) {
            canPut = true;
            for(auto point : selectPoint){
                if((r + c == point.x + point.y) || (r - c == point.y - point.x) || (r == point.y) || (c == point.x)){
                    canPut = false;
                    break;
                }
            }
            if(canPut){
                selectPoint.push_back({r, c});
                sum += findQueen(r, c, count+1, selectPoint);
                selectPoint.pop_back();
            }
        }
    }
    return sum;
}

int main()	{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n ;

    vector<Point> selectPoint;
    cout << findQueen(0, 0, 0, selectPoint);

    return 0;
}