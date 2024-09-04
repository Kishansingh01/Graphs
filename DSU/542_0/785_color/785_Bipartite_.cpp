// 2 -colour->i have to give the colour to the node(Red,Blue) such that adjacent 
// node have different colour

 // or BIpartite graph

 // We can use BFS and solve it.

 class Solution{
public:
    bool bfs(int src, vector<int>& color, vector<vector<int>>& graph) {
        queue<int> qu;
        qu.push(src);
        color[src] = 0;
        
        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            
            for (auto neighbour : graph[curr]) {
                if (color[neighbour] == -1) {
                    color[neighbour] = !color[curr];
                    qu.push(neighbour);
                } else if (color[curr] == color[neighbour]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!bfs(i, color, graph)) return false;
            }
        }
        return true;
    }
};

 