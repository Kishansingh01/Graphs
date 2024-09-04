 //  Unweighted Graphs/UNDIRECTIONAL GRAPHS

// #include<iostream>
// #include<vector>
// #include<list>
// using namespace std;

// vector<list<int> >graph;
// int v; //Number of vertices
// void add_edge(int src,int dest,bool bi_dir=true){
//     graph[src].push_back(dest);
//     if(bi_dir){
//         graph[dest].push_back(src);
//     }
// }
 
//   void display(){
//     for(int i=0;i<graph.size();i++){
//         cout<<i<<"->";
//         for(auto el:graph[i]){
//             cout<<el<<" , ";
//         }
//         cout<<"\n";
//     }
//   }

// int main(){
//        cin>>v;// Nodes
//        graph.resize(v,list<int>());
//        int e;//Edges 
//        cin>>e;
//        while(e--){
//         int s,d;   //s,d means that node to the distinated node.
//         cin>>s>>d;
//         add_edge(s,d); //Calling add_edges
//        }
//        display(); //Then displaying the connected node into the graph.
//        return 0;
// }


       //       UNWEIGHTAGE  GRAPHS/ DIRECTIONAL GRAPH

// Only we have give a false in add_edge.

#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int> >graph;
int v; //Number of vertices
void add_edge(int src,int dest,bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
 
  void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto el:graph[i]){
            cout<<el<<" , ";
        }
        cout<<"\n";
    }
  }

int main(){
       cin>>v;// Nodes
       graph.resize(v,list<int>());
       int e;//Edges 
       cin>>e;
       while(e--){
        int s,d;   //s,d means that node to the distinated node.
        cin>>s>>d;
        add_edge(s,d,false); //Calling add_edges
       }
       display(); //Then displaying the connected node into the graph.
       return 0;
}