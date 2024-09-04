// I have to find all path in from the graph till some values. How much 
// all paths can be possible till some node as we are searching in DFS logic usage.

#include<iostream>
#include<vector>
#include<list>
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
 void dfs(int curr,int end,vector<int>&path){  //(0,6) i am going from 0 to search 6,its after 1,6, its after 2,6. Its after 3,6then 4,6 then 5,6 till 6,6.
    if(curr==end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }

    visited.insert(curr);// Mark visited
    path.push_back(curr);
    for(auto neighbour:graph[curr]){//here if i have traversed to all node and if it is marked already so,it will go after the new node by traversing.
        if(not visited.count(neighbour)){
            dfs(neighbour,end,path);
           
        }
    }
    path.pop_back();//we remove
    visited.erase(curr);// and erase it from visited to go from another paths
    return;
 }

void allPath(int src,int dest){
    vector<int>v;
    dfs(src,dest,v);

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
    int x,y;
    cin>>x>>y;
    allPath(x,y);
    
    for(auto path:result){
        for(auto el:path){
            cout<<el<<" ";
        }
        cout<<"\n";
    }
    return 0;
 }

// Input i have given
// Enter v::7
// Enter e::8

// 0 1
// 0 4
// 1 3
// 4 3
// 1 5
// 5 6
// 6 2
// 5 2

// 0 6(Path from 0 to 6 i have to gop and find how many types of path are there.)

// Output that is coming nunber of types of all the paths.
// 0 1 5 6 
// 0 1 5 2 6 
// 0 4 3 1 5 6
// 0 4 3 1 5 2 6