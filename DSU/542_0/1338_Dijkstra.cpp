// 1368:: Minimum cost to make at least one valid path in a grid.

        //  Memset function to inatilize zero and 1  we take 3 arguments.Which works only with bytes.
        //  void* memset(void* ptr, int value, size_t num); or (pointers array,inalisize value, size )


// This solution i have not did with priority queue for that i have used deque 
// where i edge weight 1 put in the last bcz it will process last then put in front of 0 thats it.

class Solution{
    public:
     int minCost(vector<vector<int>> &grid){
         int n=grid.size();
         int m=grid[0].size();

         int dx[4]={0,0,1,-1};   // {0,1->right:0,-1->left:1,0->downward:-1,0->Upward}
         int dy[4]={1,-1,0,0};

         int dist[n][m];

       //  memset(dist,1e9,sizeof dist);

       for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
       dist[i][j]=1e9;
       

         dequeue<pair<int,int>>dq;
         dq.push_back({0,0});
         dist[0][0]=0;

         while(not dq.empty()){
            auto curr=dq.front();
            dq.pop_front();

            int x=curr.first;
            int y=curr.second;
            int dir=grid[x][y];

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                int edgewt=1;
                if(i+1==dir) edgewt=0; // To detect the edge weight

                if(nx<n and ny<m and nx>=0 and ny>=0){
                // next cell lies in the grid
                if(dist[nx][ny]>dist[x][y]+edgewt) {
                    dist[nx][ny]=dist[x][y]+edgewt;
                    if(edgewt==1){
                        dq.push_back({nx,ny});                     
                    }
                    else{
                        dq.push_front({nx,ny});
                    }
                }   
                }
            }
         }
         return dist[n-1][m-1];
     }
};