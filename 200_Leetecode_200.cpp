
// Sir has did this from BFS  do DFS by your own.

class Solution{
    public:
      int numIslands(vector<vector<char>>& grid){
        int rows=grid.size();
        int cols=grid[0].size();

        int cc=0// Stores the number of connected components
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]=='0'){
              // It is a water body
              continue;      
                }
                
           
    //new unvisited land piece found,i.e new connected component
    c++;
    grid[r][c]='0'; //mark it as visited
    queue<pair<int,int>qu;
    qu.push({r,c});// Store the src node.
    while(not qu.empty()){
        //BFS
        auto curr=qu.front();// get one node from queue.
        qu.pop();
        //Go to all unvisited neighbours of the current node 
        int currRow=curr.first;
        int currCol=curr.second;
        //check up
        if(currRow -1 >=0 and grid[currRow -1][currCol]=='1'){
            qu.push({currRow-1,currCol});
            grid[currRow -1][currCol]='0';
        }
         //check down
        if(currRow+1 < 0 and grid[currRow +1][currCol]=='1'){
            qu.push({currRow+1,currCol});
            grid[currRow +1][currCol]='0';
        }
         //check left
        if(currCol -1>=0 and grid[currRow][currCol-1]=='1'){
            qu.push({currRow,currCol-1});
            grid[currRow][currCol-1]='0';
        }
         //check right
        if(currCol +1 <cols and grid[currRow][currCol+1]=='1'){
            qu.push({currRow,currCol+1});
            grid[currRow][currCol+1]='0';
        }
    }
        }
      }}
      return cc;
      };


TC/SC=M*n