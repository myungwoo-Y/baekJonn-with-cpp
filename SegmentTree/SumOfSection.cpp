#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    // leaf node 일 경우
    if(start == end){
        return tree[node] = a[start];
    } else{
        return tree[node] = init(a, tree, node*2, start, (start+end)/ 2)
                            + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}

long long sum(vector<long long> &tree, int node, int start, int end ,int left, int right){
    if(left > end || right < start){
        return 0;
    }else if(left <= start && end <= right){
        return tree[node];
    }else{
        return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2 + 1, (start+end)/2 + 1, end, left, right);
    }
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
    if(index < start || end < index){
        return;
    }

    tree[node] = tree[node] + diff;

    if(start!=end){
        update(tree, node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2 + 1, end, index, diff);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, numberOfChange, numberOfSum;
    cin >> n >> numberOfChange >> numberOfSum;
    int height = ceil(log2(n)) + 1;
    int treeSize = pow(2, height);
    vector<long long> arr(n+1);
    vector<long long> tree(treeSize+1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    init(arr, tree, 1, 1, n);

    int caseOfAction, a, b;
    for (int i = 0; i < numberOfChange + numberOfSum; ++i) {
        cin >> caseOfAction >> a >> b;

        if(caseOfAction == 1){
            update(tree, 1, 1, n, a, (long long)b - sum(tree, 1, 1, n, a, a));
        }else if(caseOfAction != 1){
            cout << sum(tree, 1, 1, n, a, b) << '\n';
        }
    }


    return 0;
}









