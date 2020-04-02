#include <bits/stdc++.h>

#define VII vector<vector<int>>
#define VDD vector<vector<double>>
#define VCC vector<vector<char>>
#define VSS vector<vector<string>>
#define VBB vector<vector<bool>>
#define VLL vector<vector<long long>>
#define VI vector<int>
#define VB vector<bool>
#define VS vector<string>
#define VC vector<char>
#define VD vector<double>
#define VL vector<long long>
#define SI string::iterator
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>

using namespace std;
const string endL = "\n";

const int Max = 99999999;

struct D{
    int s {}, d {}, l {};
};

vector<D> dists;
VI dp;
int n {}, d {};

int distance(int cur){
    int size = dists.size();
    if(cur >= size){
//        cout << cur << " " << dists.size() << endL;
        return Max;
    }

    int dist = Max;
    D now = dists[cur];
    for (int i = cur+1; i < dists.size(); ++i) {
        D next = dists[i];
        if(now.d <= next.s && next.d <= d){
            dist = min(dist, distance(i) + next.l + next.s - now.d);
        }
    }
    dist = min(dist, d-now.d);
//    dist = min(dist, distance(cur+1));

    if(dist < 0){
        return Max;
    }
    return dist;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #endif


    cin >> n >> d;
    dists = vector<D>(n);
    dp = VI(n);
    for (int i = 0; i < dists.size(); ++i) {
        D data;
        cin >> data.s >> data.d >> data.l;
        dists[i] = data;
    }

    sort(dists.begin(), dists.end(),
            [](D& a, D& b){
                return a.s <  b.s;
    });

    int rtnMin {d};

    for (int i = 0; i < n; ++i) {
        rtnMin = min(rtnMin, distance(i) + dists[i].s + dists[i].l);
    }

    cout << rtnMin;

    return 0;
}