// DS- Visitd set,priority_queue<pair>,unordered_map

// insert the pair of <-1, src> in the pq.

// one by one i will remove the root of the pq

// if the root element is already visited, then we will just continue. 

// we mark the root visited 
// we store the weight of the oair in the ans 

// update the mapping 

// go to every neighbour of the current element ,and only add those which are 
// not visited and have a better weight preposition.

#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;

vector<list<pp>>graph;

void add_edge(int u,int v,int wt,bool bidir=true){
    graph[u].push_back({v,wt});
    if(bidir){
        graph[v].push_back({u,wt});
    }
}
ll prims(int src,int n){
    priority_queue<pp, vector<pp>,greater<pp>>pq;//In that queue first element will be weight and second will be node
    unordered_set<int>vis;
    vector<int>par(n+1);
    unordered_map<int,int>mp; //Priority queue me pair me pahle weight aata hai phir Node aata hai
    for(int i=1;i<=n;i++){   //1 based indexing.
        mp[i]=INT_MAX;
    }
    pq.push({0,src});
    mp[src]=-1;
    int total_count=0; //0->(n-1) edges
    int result=0; // Sum of weights
    while(total_count < n && ! pq.empty()){
       // cout<<total_count<<" "<<result<<endl;

       // cout<<total_count<<endl;
       pp curr=pq.top();
       if(vis.count(curr.second)){  //current variable is priority queue variable
        pq.pop();
        continue;
       }
       vis.insert(curr.second);
       total_count++;
       result+=curr.first;
       pq.pop();
      // cout<<"neighbour"<<endl;
       for(auto neighbour:graph[curr.second]){ // Neighbour is graph variable.
       //  graph ke pair me pahle node aata hai phir weight aata hai.
          if(!vis.count(neighbour.first)and mp[neighbour.first]> neighbour.second){
            pq.push({neighbour.second,neighbour.first});
            par[neighbour.first]=curr.second;
            mp[neighbour.first]=neighbour.second;// mapping updation
          }
       }
    //   cout<<"done"<<endl;
    }
    return result;
}
int main(){
    int n,m;  //n,m=no of nodes and edges
    cin>>n>>m;
    graph.resize(n+1,list<pp>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<"--";
    //     for(auto neigh:graph[i]){
    //         cout<<"("<<neigh.first<<","<<neigh.second<<")";
    //     }   This is for graph making.
    //     cout<<"\n";
    // }
    int src;
    cin>>src;
    cout<<prims(src,n)<<endl;
    return 0;

}

//  My input given
// 5 6
// 1 2 3
// 1 3 4
// 4 2 6
// 5 2 2
// 2 3 5
// 3 5 7
// 1
// 15  //Output