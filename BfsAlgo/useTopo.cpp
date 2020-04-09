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
const string endL {"\n"};
VBB adj;
VS arr;
VB visited;
VI visitOrder;
const int alphaN = 26;


void makeGraph(){
    for (int i = 1; i < arr.size(); ++i) {
        string f = arr[i - 1];
        string s = arr[i];
        int len = min(f.length(), s.length());
        for (int idx = 0; idx < len; ++idx) {
            if(f[idx] != s[idx]){
                int r = f[idx]-'a';
                int c = s[idx]-'a';
                adj[r][c] = true;
                break;
            }
        }
    }
}

void dfs(int here){
    visited[here] = true;
    for (int i = 0; i < alphaN; ++i) {
        if(adj[here][i] && !visited[i]){
            dfs(i);
        }
    }
    visitOrder.push_back(here);
}


void makeOrder(){
    for (int i = 0; i < alphaN; ++i) {
        bool hasAdj {false};

        for (int j = 0; j < alphaN; ++j) {
            if(adj[i][j] == true){
                hasAdj = true;
                break;
            }
        }

        if(hasAdj && !visited[i]){
            dfs(i);
        }
    }

    reverse(visitOrder.begin(), visitOrder.end());

    for (int i = 0; i < visitOrder.size(); ++i) {
        for (int j = i+1; j < visitOrder.size(); ++j) {
            int a = visitOrder[j];
            int b = visitOrder[i];
            if(adj[a][b]){
                visitOrder = VI();
                return;
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
        int n {};
        cin >> n;
        arr = VS(n);
        adj = VBB(alphaN, VB(alphaN));
        visitOrder = VI();
        visited = VB(alphaN);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        makeGraph();
        makeOrder();
        if(visitOrder.size() == 0){
            cout << "INVALID HYPOTHESIS";
        }else{
            bool hasSequnce {true};
            for (int i = 1; i < visitOrder.size(); ++i) {
                if(visitOrder[i-1] > visitOrder[i]){
                    hasSequnce = false;
                    break;
                }
            }
            if(hasSequnce){
                for (int i = 0; i < alphaN; ++i) {
                    cout << string(1,i+'a');
                }
            }else{
                for(auto idx : visitOrder){
                    cout << string(1,idx+'a');
                }
                for (int i = 0; i < alphaN; ++i) {
                    if(!visited[i]){
                        cout << string(1,i+'a');
                    }
                }
            }
        }

        cout << endL;
    }



    return 0;
}