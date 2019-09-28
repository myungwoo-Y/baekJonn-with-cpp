#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <time.h>

typedef long long LL;

using namespace std;

LL init(vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    // leaf node 일 경우
    if(start == end){
        return tree[node] = a[start];
    } else{
        return tree[node] = min(init(a, tree, node*2, start, (start+end)/ 2)
                ,init(a, tree, node*2+1, (start+end)/2+1, end));
    }
}

LL sum(vector<long long> &tree, int node, int start, int end ,int left, int right){
    if(left > end || right < start){
        return INT32_MAX;
    }else if(left <= start && end <= right){
        return tree[node];
    }else{
        return min(sum(tree, node*2, start, (start+end)/2, left, right)
                ,sum(tree, node*2 + 1, (start+end)/2 + 1, end, left, right));
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int height = ceil(log2(n)) + 1;
    int treeSize = pow(2, height);
    vector<long long> arr(n+1);
    vector<long long> tree(treeSize+1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    init(arr, tree, 1, 1, n);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        cout << sum(tree, 1, 1, n, a, b) << '\n';
    }

    return 0;
}









