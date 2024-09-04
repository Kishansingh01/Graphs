// i can use DFS on graph or BFS on graphs.
class Solution{
    public:
         bool canVisitAllRooms(vector<int>&rooms){
          
          
          
          
            unordered_set<int>visited;
            queue<int>qu;
            qu.push(0);
            visited.insert(0);
            while(!qu.empty()){
                int curr=qu.front();
                qu.pop();
                for(int neighbour:rooms[curr]){
                    if(visited.count(neighbour)==0){
                        //neighbour not yet visited
                        qu.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
            return visited.size==rooms.size();//Denotes the number of rooms.
         }
};