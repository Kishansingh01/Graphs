
// Given an undirected weighted graph,given with a src and destination.
// Find the shortest path between the source and destination in terms of sum 
// of edge costs.
// In dirextra we use the priority queues.

// Deque-> it allows insertion from the front and the rear.

//  1e9=1*10^9
// Approach 

//function Dijkstra(Graph, source):
    // create a priority queue Q
    // dist[source] ← 0
    // for each vertex v in Graph:
    //     if v ≠ source:
    //         dist[v] ← infinity
    //     add v to Q

    // while Q is not empty:
    //     u ← vertex in Q with smallest distance in dist[]
    //     remove u from Q

    //     for each neighbor v of u:
    //         alt ← dist[u] + length(u, v)
    //         if alt < dist[v]:
    //             dist[v] ← alt
    //             parent[v] ← u

    // return dist[]


#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <algorithm>  // for reverse

using namespace std;

typedef pair<int, int> pii;  // Pair to store (distance, vertex)
typedef vector<vector<pii>> Graph;

// Function to find the shortest path using Dijkstra's algorithm
vector<int> dijkstra(const Graph &graph, int src, int dest) {
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max());  // Distance from src to each vertex
    vector<int> parent(n, -1);  // To store the path
    priority_queue<pii, vector<pii>, greater<pii>> pq;  // Min-heap

    // Start from the source
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        cout << "Processing node " << u << " with current distance " << dist[u] << endl;

        // If we reach the destination, no need to proceed further
        if (u == dest) break;

        // Visit all the neighbors of u
        for (const auto &neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            cout << "   Neighbor " << v << " with edge weight " << weight << endl;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                parent[v] = u;

                cout << "   Updated distance of " << v << " to " << dist[v] << endl;
            }
        }
    }

    // Reconstruct the shortest path from src to dest
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    Graph graph(n);
    cout << "Enter the edges (u, v, weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});  // Because the graph is undirected
    }

    int src, dest;
    cout << "Enter the source and destination: ";
    cin >> src >> dest;

    vector<int> path = dijkstra(graph, src, dest);

    if (path.size() == 1 && path[0] == src) {
        cout << "No path exists from " << src << " to " << dest << endl;
    } else {
        cout << "Shortest path from " << src << " to " << dest << ": ";
        for (int vertex : path) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}

