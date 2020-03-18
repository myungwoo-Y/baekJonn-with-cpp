#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n {0}, deleteNode {0}, root {0};

    cin >> n;

    vector<int> parents(n);

    vector<bool> isLeaf(n, true);
    vector<int> leafCounts(n);

    for (int i = 0; i < n; ++i) {
        cin >> parents[i];

        if(parents[i] >= 0){
            isLeaf[parents[i]] = false;
        }else if(parents[i] == -1){
            root = i;
        }
    }

    cin >> deleteNode;

    int node {0}, child {0}, temp {0};
    for (int i = 0; i < isLeaf.size(); ++i) {
        if(isLeaf[i]){
            node = i;
            while(node != -1){
                node = parents[node];
                if(node == -1) break;
                leafCounts[node]++;
            }
        }
    }

    if(deleteNode == root){
        cout << 0;
    }else if(leafCounts[deleteNode] +  isLeaf[deleteNode] == leafCounts[parents[deleteNode]]){
        cout << leafCounts[root] - leafCounts[deleteNode] + 1 - isLeaf[deleteNode];
    }else{
        cout << leafCounts[root] - leafCounts[deleteNode] - isLeaf[deleteNode];
    }

    return 0;
}