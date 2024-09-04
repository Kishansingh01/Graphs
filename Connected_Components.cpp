
#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
int v; // Number of vertices

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

void dfs(int node, unordered_set<int>& visited) { 
    visited.insert(node);
    for (auto neighbour : graph[node]) { // Traverse all neighbors
        if (not visited.count(neighbour)) {
            dfs(neighbour, visited);
        }
    }
}

int connected_components() {
    int result = 0;
    unordered_set<int> visited;
    for (int i = 0; i < v; i++) {
        // If a vertex hasn't been visited, we have found a new component
        if (visited.count(i) == 0) {
            result++;
            dfs(i, visited);
        }
    }
    return result;
}

int main() {
    cin >> v; // Nodes
    graph.resize(v); // Resize graph for 'v' vertices
    int e; // Edges 
    cin >> e;
    while (e--) {
        int s, d; // Source and destination nodes
        cin >> s >> d;
        add_edge(s, d, false); // Calling add_edge, assuming undirected graph
    }
    cout << connected_components() << endl; // Correct function call
    return 0;
}
