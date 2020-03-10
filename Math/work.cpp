#include <iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long x {0}, y {0}, straightTime {0}, diagonalTime {0};

    cin >> x >> y >> straightTime >> diagonalTime;

    long long totalStraightTime = (x + y) * straightTime;

    long long minCoordinates = min(x, y);
    long long maxCoordinates = max(x, y);


    long long combiTime = (maxCoordinates - minCoordinates) * straightTime + minCoordinates * diagonalTime;

    // 최대한 대각선을 이용하고 싶을 경우
    long long onlyDiagonalTime {0};
    // 대각선만으로 목적지 도착할 경우
    if((x+y)%2 == 0){
        onlyDiagonalTime = (maxCoordinates - minCoordinates) * diagonalTime + minCoordinates * diagonalTime;
    // 목적지 좌표의 합이 짝수가 아니라 대각선만으로 접근 할 수 없을 경우
   }else{
        onlyDiagonalTime = (maxCoordinates - minCoordinates - 1) * diagonalTime + minCoordinates * diagonalTime + straightTime;
    }

    cout << min({totalStraightTime, combiTime, onlyDiagonalTime});

    return 0;
}

