#include<cstdio>
#include<algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> participants;
    for (string name : participant) {
        ++participants[name];
    }
    for (string name : completion) {
        --participants[name];
    }
    for (auto pair : participants) {
        if (pair.second > 0) { return pair.first; }
    }
}

int main() {
    vector<string> a{"mislav", "stanko", "mislav", "ana"};
    vector<string> b{"stanko", "mislav", "ana"};
    printf("%s", solution(a, b).c_str());

    return 0;
}


