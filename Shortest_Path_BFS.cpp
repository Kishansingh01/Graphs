//   I have to find shortest path from the BFS.


// i can use parents like as Deepak sir told but we are going with current.

#include<iostream>
#include<vector>
#include<climits>
#include<list> 
#include<queue>
#include<unordered_set>
using namespace std;

vector<list<int>>graph;
unordered_set<int>visited;

vector<vector<int>>result;

int v; //Number of vertices
void add_edge(int src,int dest,bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

 void bfs(int src,vector<int>&dist){
    queue<int>qu;
    visited.clear();
    dist.resize(v,INT_MAX);
    dist[src]=0;
    visited.insert(src);
    qu.push(src);
    while(not qu.empty()){
        int curr=qu.front();
        cout<<curr<<" ";
        qu.pop();
        for(auto neighbour:graph[curr]){
            if(not visited.count(neighbour)){
                qu.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour]=dist[curr]+1;
            }
        }
    }
    cout<<"\n";

 }

 int main(){
    cout<<"Enter v::";
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cout<<"Enter e::";
    cin>>e;
    visited.clear();
    while(e--){
        int s,d; //s=source,D=Destination
         cin>>s>>d;
         add_edge(s,d);}
    int x;
    cin>>x;
    vector<int>dist;
    bfs(x,dist);
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    return 0;
 }























// #include<iostream>
// #include<vector>
// #include<climits>
// #include<list>
// #include<queue>
// #include<unordered_set>
// using namespace std;

// vector<list<int>>graph;
// unordered_set<int>visited;

// vector<vector<int>>result;

// int v; //Number of vertices
// void add_edge(int src,int dest,bool bi_dir=true){
//     graph[src].push_back(dest);
//     if(bi_dir){
//         graph[dest].push_back(src);
//     }
// }

//  void bfs(int src,int dest,vector<int>&dist){
//     queue<int>qu;
//     visited.clear();
//     dist.resize(v,INT_MAX);
//     dist[src]=0;
//     visited.insert(src);
//     qu.push(src);
//     while(not qu.empty()){
//         int curr=qu.front();
//         cout<<curr<<" ";
//         qu.pop();
//         for(auto neighbour:graph[curr]){
//             if(not visited.count(neighbour)){
//                 qu.push(neighbour);
//                 visited.insert(neighbour);
//                 dist[neighbour]=dist[curr]+1;
//             }
//         }
//     }
//     cout<<"\n";

//  }

//  int main(){
//     cout<<"Enter v::";
//     cin>>v;
//     graph.resize(v,list<int>());
//     int e;
//     cout<<"Enter e::";
//     cin>>e;
//     visited.clear();
//     while(e--){
//         int s,d; //s=source,D=Destination
//          cin>>s>>d;
//          add_edge(s,d);}
//     int x,y;
//     cin>>x>>y;
//     vector<int>dist;
//     bfs(x,y,dist);
//     for(int i=0;i<dist.size();i++){
//         cout<<dist[i]<<" ";
//     }
//     return 0;
//  }