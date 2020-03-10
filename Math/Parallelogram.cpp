#include <iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#define endl '\n'
using namespace std;

struct Point{
    int x, y;
};

// 두 점간 거리 구하는 함수이다.
double getDistance(Point a, Point b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double solve(vector<Point> points){
    // 세점이 모두 평행일때 -1을 반환한다.
    // 평행여부는 기울기를 이용하여 구한다.
    if((points[0].x-points[1].x)*(points[1].y-points[2].y) == (points[0].y-points[1].y)*(points[1].x-points[2].x)){
        return -1;
    }

    // 가능한 모든변의 각 길이를 구한다.
    // 2를 곱하는 이유는 둘레를 구할 경우 각 변이 2번씩 더해지기 때문이다.
    double a = getDistance(points[0], points[1])*2;
    double b = getDistance(points[1], points[2])*2;
    double c = getDistance(points[0], points[2])*2;

    // min과 max 는 길이가 가장 큰 변과 가장 작은 변을 제외한 변은 서로 중복되기 때문에
    // 차이를 구할때는 중복되는 변의 크기는 구하지 않아도 자동으로 제거된다.
    return max({a,b,c}) - min({a,b,c,});
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<Point> points(3);

    for (int i = 0; i < 3; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    cout.precision(11);
    cout << solve(points);

    return 0;
}





