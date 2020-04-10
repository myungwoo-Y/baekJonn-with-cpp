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
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>

using namespace std;
const string endL = "\n";
int n {};
VI arr;
VII checkAdj;
VII adj;
VI indegree;
VI topoList;
unordered_map<int, int> m;
auto compare = [](int& a, int& b){
    return m[a] > m[b];
};
priority_queue<int, vector<int>, decltype(compare)> pq(compare);

bool isCycle(){
    for (int i = 1; i < topoList.size(); ++i) {
        int down = topoList[i];
        for (int j = i-1; j >= 0; --j) {
            int up = topoList[j];
            if(m[down] < m[up] && checkAdj[up][down] == 0){
                return true;
            }

        }
    }
    return false;
}

void topo(){
    for (int i = 1; i <= n; ++i) {
        if(indegree[i] == 0)
            pq.push(i);
    }

    while(!pq.empty()){
        int here = pq.top();
        topoList.push_back(here);
        pq.pop();
        for(auto next : adj[here]){
            if(--indegree[next] == 0){
                pq.push(next);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    int testCase {};
    cin >> testCase;

    loop(testCase){
        cin >> n;

        topoList.clear();
        m.clear();

        adj = VII(n+1);
        checkAdj = VII(n+1, VI(n+1));
        arr = VI(n);
        indegree = VI(n+1);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            m[arr[i]] = i+1;
        }
        int graphN {};
        bool notCorrect {false};
        cin >> graphN;
        loop(graphN){
            int p {}, c {};
            cin >> p >> c;
            if(m[p] < m[c]){
                tie(p, c) = make_pair(c, p);
            }
            adj[p].push_back(c);
            checkAdj[p][c]++;
            indegree[c]++;
        }

        topo();

        if(notCorrect){
            cout << "IMPOSSIBLE";
        }else{
            if(isCycle()){
                cout << "IMPOSSIBLE";
            }else{
                for (auto a : topoList) {
                    cout << a << " ";
                }
            }
        }

        cout << endL;

    }


    return 0;
}