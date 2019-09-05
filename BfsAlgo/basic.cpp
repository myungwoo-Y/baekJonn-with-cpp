#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

#define Number_Of_Node 6

struct Edge{
    int src, dest;
};

class Graph{
public:
    vector<vector<int>> adjList;

    Graph(vector<Edge> const &edges){
        adjList.resize(Number_Of_Node);
        for(auto edge : edges){
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

void BFS(Graph const &graph, vector<bool>& visited, queue<int> queueForBfs){

    while(!queueForBfs.empty()){
        int src = queueForBfs.front();
        visited[src] = true;
        queueForBfs.pop();
        cout << src << " ";

        for(auto vertex : graph.adjList[src]){
            if(!visited[vertex]){
                visited[vertex] = true;
                queueForBfs.push(vertex);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio();

    queue<int> queueForBfs;
    queueForBfs.push(1);
    vector<Edge> edges = {
            {1, 2},
            {1, 3},
            {2, 4},
            {4, 3},
            {4, 5},
    };

    vector<bool> visited(Number_Of_Node);
    Graph graph(edges);
    BFS(graph, visited, queueForBfs);

    return 0;
}






