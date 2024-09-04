
// For the Undirected weightage adjacent i am usin the ordered map.Mtlb dono taraf node har ek node se jude hue hai


// #include<iostream>
// #include<vector>
// #include<list>
// using namespace std;

// vector<list<pair<int,int> > >graph;

// int v; //Number of vertices
// void add_edge(int src,int dest,int wt,bool bi_dir=true){
//     graph[src].push_back({dest,wt});
//     if(bi_dir){
//         graph[dest].push_back({src,wt});
//     }
// }
 
//   void display(){
//     for(int i=0;i<graph.size();i++){
//         cout<<i<<"->";
//         for(auto el:graph[i]){
//             cout<<"("<<el.first<<" "<<el.second<<"),";
//         }
//         cout<<"\n";
//     }
//   }

// int main(){
//        cin>>v;// Nodes
//        graph.resize(v,list<pair<int,int>>());
//        int e;//Edges 
//        cin>>e;
//        while(e--){
//         int s,d,wt;   //s,d,wt means that node to the distinated node.
//         cin>>s>>d>>wt;
//         add_edge(s,d,wt); //Calling add_edges
//        }
//        display(); //Then displaying the connected node into the graph.
//        return 0;
// }

                        
         // For the Undirected weightage adjacent i am usin the ordered map.

        
#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<pair<int,int> > >graph;

int v; //Number of vertices
void add_edge(int src,int dest,int wt,bool bi_dir=true){
    graph[src].push_back({dest,wt}); //first will destination(attactment),weightage.
    if(bi_dir){
        graph[dest].push_back({src,wt});
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
       cin>>v;// Nodes
       graph.resize(v,list<pair<int,int>>());
       int e;//Edges 
       cin>>e;
       while(e--){
        int s,d,wt;   //s,d,wt(source,destination,weight) means that node to the distinated node.
        cin>>s>>d>>wt;
        add_edge(s,d,wt,false); //Calling add_edges
       }
       display(); //Then displaying the connected node into the graph.
       return 0;
}
