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

unordered_map<int, string> m;
const int alphaN {26};
VII adj;
// vector 2차원 배열 생성
// graph[i][j] 의 결과물 역시 vector<string>이다.
// 3차원 배열을 생성한것과 마찬가지이다.(생성 배열 + 1 차수)
VS graph[alphaN][alphaN];
VI indegree, outdegree;

void makeGraph(const vector<string>& words){
    for (int i = 0; i < alphaN; ++i) {
        for (int j = 0; j < alphaN; ++j) {
            graph[i][j].clear();
        }
    }
    adj = VII(alphaN, VI(alphaN));
    indegree = outdegree = VI(alphaN);
    for(auto word : words){
        int p = word[0]-'a';
        int c = word[word.length()-1]-'a';

        graph[p][c].push_back(word);
        adj[p][c]++;

        // 차수 계산산
       outdegree[p]++;
       indegree[c]++;
    }
}

void getEulerCircuit(int here, VI& circuit){
    for (int i = 0; i < adj[here].size(); ++i) {
        // 간선을 모두 지울 때 까지 반복해야한다.
        // 현재 간선을 지운 후 다음 과정을 반복하면
        // 현재 인덱스가 2보다 크더라고 다음 과정중에 지워저야 한다.
        // 그렇지 않으면 다시 반
        while(adj[here][i] > 0){
            adj[here][i]--;
            getEulerCircuit(i, circuit);
        }
    }
    circuit.push_back(here);
}

VI getEulerTrailOrCircuit(){
    VI circuit;

    // train 같은 경우에는 시작점에서 시작해야 해답이 나온다.
    for (int i = 0; i < alphaN; ++i) {
        if(outdegree[i] == indegree[i]+1){
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }

    for (int i = 0; i < alphaN; ++i) {
        if(outdegree[i]){
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    return circuit;
}

// 오일러 서킷 / 트레일 존재 여부 확인해준다.
bool checkEuler() {
    // 시작점 있는지 여부 확인
    int plusOne {0}, minusOne {0};
    for (int i = 0; i < alphaN; ++i) {
        int delta = outdegree[i]-indegree[i];
        if(delta < -1 || delta > 1) return false;
        plusOne += delta==1;
        minusOne += delta==-1;
    }

    return (plusOne == 1 && minusOne == 1) || (plusOne==0 && minusOne==0);
}

string solve(const VS& strs){
    makeGraph(strs);

    if(!checkEuler()) return "IMPOSSIBLE";

    VI ans = getEulerTrailOrCircuit();

    if(ans.size() != strs.size() + 1) return "IMPOSSIBLE";

    reverse(ans.begin(), ans.end());
    string ret;
    for (int i = 1; i < ans.size(); ++i) {
        int p = ans[i-1], c = ans[i];
        string str = graph[p][c].back();
        graph[p][c].pop_back();

        if(ret.size()) ret += " ";
        ret += str;
    }

    return ret;
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

        VS strs(n);

        for (int i = 0; i < n; ++i) {
            cin >> strs[i];
        }

        cout << solve(strs) << endL;

    }

    return 0;
}