 // We cannot do push_back in map.
#include<iostream>
 #include<vector>
 #include<unordered_map>
 using namespace std;

 vector<unordered_map<int,int>>graph;

 int v;// Number of vertices
 void add_edge(int src,int dest,int wt,bool bi_dir=true){
     graph[src][dest]=wt;
     if(bi_dir){
        graph[dest][src]=wt;
     }
 } 
 
   void display(){
     for(int i=0;i<graph.size();i++){
         cout<<i<<"->";
         for(auto el:graph[i]){
             cout<<"("<<el.first<<" "<<el.second<<"),";
         }
         cout<<"\n";
     }
   }

 int main(){
        cin>>v; // Nodes
        graph.resize(v,unordered_map<int,int>());
        int e;  //Edges 
        cin>>e;
        while(e--){
         int s,d,wt;  //  s,d,wt means that node to the distinated node.
         cin>>s>>d>>wt;
         add_edge(s,d,wt); // Calling add_edges
        }
        display();  // Then displaying the connected node into the graph.
        return 0;
 }