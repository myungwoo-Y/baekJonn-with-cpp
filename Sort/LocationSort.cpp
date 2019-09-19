#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct Location{
    int x, y;
};

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int x, y;
    vector<Location> arr;

    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        arr.push_back(Location({x, y}));
    }

    sort(arr.begin(), arr.end(),
         [](const Location& a, const Location& b) -> bool {
             if(a.x == b.x){
                 return a.y < b.y;
             }else{
                 return a.x < b.x;
             }
         });

    for(auto element : arr){
        cout << element.x  << " " << element.y << '\n';
    }

    return 0;
}









