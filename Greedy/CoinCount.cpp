#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>


using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int numberOfCoin, destCost, count = 0;

    cin >> numberOfCoin >> destCost;

    vector<int> costs;
    int cost;
    for (int i = 0; i < numberOfCoin; ++i) {
        cin >> cost;
        costs.push_back(cost);
    }

    for (int index = costs.size()-1; destCost > 0; --index) {
        if(destCost/costs[index] > 0){
            count += destCost/costs[index];
        }
        destCost -= (destCost/costs[index]) * costs[index];
    }

    cout << count;

    return 0;
}






