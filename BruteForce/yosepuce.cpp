/*
 백준  1168번
 요세푸스 문제 2
 *
 *
 */

#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define LOCAL
using namespace std;

static string endL = "\n";

int main(void) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #endif

    int n {0}, deleteSq {0};

    cin >> n >> deleteSq;

    vector<int> arr;

    for (int i = 1; i <= n; ++i) {
        arr.push_back(i);
    }

    cout << '<';
    for (int index = 0; arr.size() != 0;) {
        if(arr.size() == 1){
            cout << *arr.begin();
            break;
        }
        int next = (index+(deleteSq-1)) % arr.size();
        cout << arr[next] << ", ";
        arr.erase(arr.begin() + next);
        index = next;
    }
    cout << ">";


    return 0;
}