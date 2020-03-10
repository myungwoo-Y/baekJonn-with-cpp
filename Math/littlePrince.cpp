#include <iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#define endl '\n'
using namespace std;

struct Point{
    int x, y;
};

struct Circle{
    int x, y, radius;

    Circle(int _x, int _y, int _radius){
        x = _x;
        y = _y;
        radius = _radius;
    }

    Circle(){}
};

double calDistance(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

// 바깥에 도달할 때 까지 start 노드의 부모를 찾아간다. 동시에 height도 마크한다.
int markStartHeight(int parent, vector<int>& parentInfo, vector<int>& heightMark, int height){
    if(parent == 0){
        heightMark[parent] = height;
        return height;
    }else{
        heightMark[parent] = height;
        parent = parentInfo[parent];
        return markStartHeight(parent, parentInfo, heightMark, ++height);
    }
}

int getDifferHeight(int parent, vector<int>& parentInfo, vector<int>& heightMark){
    int destHeight {0};
    while(true){
        if(heightMark[parent] != 0){
            return heightMark[parent] + destHeight - 1;
        }else{
            destHeight++;
            parent = parentInfo[parent];
        }
    }
}

int solve(Point start, Point dest, vector<Circle> circles){
    circles.push_back(Circle(start.x, start.y, 0));
    circles.push_back(Circle(dest.x, dest.y, 0));

    vector<int> parentInfo(circles.size()+1);
    vector<int> heightMark(circles.size() + 1);
    Circle parent, child;
    int distance {0};

    // 각 노드의 부모를 찾는다.
    // 0번째 부모는 바깥을 의미한다.
    // 때문에 각 노드는 1 부터 시작한다.
    for(int p = 0; p < circles.size(); p++){
        parent = circles[p];
        for (int c = p + 1; c < circles.size(); ++c) {
            child = circles[c];
            distance = calDistance(parent.x, parent.y, child.x, child.y);
            if(distance + child.radius < parent.radius){
                parentInfo[c+1] = p+1;
            }
        }
    }


    int startIndex = circles.size()-1, destIndex = circles.size();

    markStartHeight(parentInfo[startIndex], parentInfo, heightMark, 1);

    return getDifferHeight(parentInfo[destIndex], parentInfo, heightMark);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testCount {0}, numberOfCircle;
    vector<Circle> circles;
    cin >> testCount;

    Point start, dest;

    int x {0}, y {0}, radius {0};

    for (; testCount > 0; --testCount) {
        cin >> start.x >> start.y;
        cin >> dest.x >> dest.y;

        cin >> numberOfCircle;
        circles.resize(numberOfCircle);

        for (int i = 0; i < numberOfCircle; ++i) {
            cin >> x >>y >> radius;
            circles[i] = Circle(x, y, radius);
        }

        sort(circles.begin(), circles.end(), [](Circle a, Circle b){return a.radius > b.radius;});

        cout << solve(start, dest, circles) << endl;
    }
    return 0;
}

