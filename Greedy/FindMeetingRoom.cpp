#include<cstdio>
#include<algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <ctime>

using namespace std;

bool comp(pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b) {
    if (a.second == b.second) {
        return b.first > a.first;
    } else {
        return b.second > a.second;
    }
}

int find(vector<pair<unsigned int, unsigned int>> arr) {
    sort(arr.begin(), arr.end(), comp);
    int cnt = 0;
    unsigned int limitStartTime;
    for (auto timePair : arr) {
        if (cnt == 0) {
            limitStartTime = timePair.second;
            ++cnt;
        } else {
            if (timePair.first >= limitStartTime) {
                limitStartTime = timePair.second;
                ++cnt;
            }
        }
    }
    return cnt;
}

int main() {
    int n;
    unsigned int s, e;
    scanf("%d", &n);
    vector<pair<unsigned int, unsigned int>> arr;
    for (int i = 0; i < n; ++i) {
        scanf("%u %u", &s, &e);
        arr.push_back(pair<unsigned int, unsigned int>(s, e));
    }
    printf("%d", find(arr));
    return 0;
}



