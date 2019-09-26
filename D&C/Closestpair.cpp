#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <time.h>

struct pt {
    int x, y, id;
};

using namespace std;

int n;
vector<pt> a;
double mindist;
int result;
pair<int, int> best_pair;
vector<pt> t;

void upd_ans(const pt & a, const pt & b){
    double dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    if(dist < mindist){
        result = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
        mindist = dist;
        best_pair = {a.id, b.id};
    }
}

void rec(int l, int r){

    // brute force
    if (r - l <= 3){
        for (int i = l; i < r; ++i) {
            for (int j = i+1; j < r; ++j) {
                upd_ans(a[i], a[j]);
            }
        }
        sort(a.begin() + l, a.begin() + r,
             [](const pt & a, const pt & b){
                 return a.y < b.y;
             });
        return;
    }

    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec(l, m);
    rec(m, r);

    // l 부터 m 까지 y 를 기준으로 sort 해서 merge
    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(),
          [](const pt & a, const pt & b){
              return a.y < b.y;
          });

    // t의 (r - l) 개의 원소를 a의 l번째 원소부터 집어넣는다.
    // 즉 , a의 l부터 r까지의 원소를 y순으로 정렬하는것이다.
    copy(t.begin(), t.begin() + r - l, a.begin() + l);

    int tsz = 0;
    for (int i = l; i < r; ++i) {
        // a의 i번째 원소가 가운데 점으로부터 수평으로 mindist보다 적게 떨어져 있을때
        if(abs(a[i].x - midx) < mindist){

            // y값이 낮은것부터 비교한다.
            // i번째 인덱스 원소의 y값보다 낮은 y값을 가진 원소들만 검사한다.
            // 두 원소의 y값 차이는 mindist보다 작아야 비교한다.
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y <  mindist; --j) {
                upd_ans(a[i], t[j]);
            }
            // if 에서 적용한 규칙을 통과한 a[i]만 t에 쌓는다.
            t[tsz++] = a[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int x, y;
    cin >> n;
    t.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        a.push_back(pt({x, y, i}));
    }
    sort(a.begin(), a.end(),
         [](const pt & a, const pt & b){
             return a.x < b.x;});

    mindist = 1E20;

    rec(0, n);

    cout << result;


    return 0;
}









