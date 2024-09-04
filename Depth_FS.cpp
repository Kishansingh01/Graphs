//   To read any graph we have two major techniques-
//   1)Depth first traversal    (Stack)// traversing parent to child to down
//   2)Breadth first traversal  (Queue)//Traversing levelwise.

// Question: Given a graph check whether there is a path between any 
//            two vertices or not.

//SRC means from where i have started the node or vertices.

// In DFS there is the recursion thats why we are using stack there.

// I am doiing graph by using depth first search .and i am finding the 
// path which i wanted. 

// Time complexity->Since i am going through vertices to edges. So,
// timecomplexity will be O(E+V) and space complexity will be O(V) in worst case. 

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>>graph;
unordered_set<int>visited;
int v; //Number of vertices
void add_edge(int src,int dest,bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
 bool dfs(int curr,int end){  //(0,6) i am going from 0 to search 6,its after 1,6, its after 2,6. Its after 3,6then 4,6 then 5,6 till 6,6.
    if(curr==end) return true;
    visited.insert(curr);// Mark visited
    for(auto neighbour:graph[curr]){//here if i have traversed to all node and if it is marked already so,it will go after the new node by traversing.
        if(not visited.count(neighbour)){
            bool result=dfs(neighbour,end);
            if(result) return true;
        }
    }
    return false;
 }

bool anyPath(int src,int dest){
    return dfs(src,dest);

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
         add_edge(s,d,false);}
    int x,y;
    cin>>x>>y;
    cout<<anyPath(x,y)<<"\n";
    return 0;
 }

// (We know that in circular graph if there is n node so edges 
// should be n+1.)

// 7(vertices) i am taking.

// 8(Edges) i am taking.

// 0 1
// 0 4
// 1 3
// 4 3
// 1 5
// 5 6
// 6 2
// 5 2

// 0 6(Here i have to check from 0 to 6 it will whether exist or not.)

// 1(Answer should by yes exist)

 