#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int find(vector<int>&parent,int a){
    return parent[a]=((parent[a]=a)?a:find(parent,parent[a]));
}

void Union(vector<int>&par,vector<int>&rank,int a,int b){
    a=find(par,a);
    b=find(par,b);
    if(a==b) return ;
    if(rank[a]>=rank[b]){
        rank[a]++;
        par[b]=a; //Par=parents
    }
    else{
        rank[b]++;
        par[a]=b;
    }
}

struct Edge{
    int src;
    int dest;
    int wt;

};

bool cmp(Edge e1,Edge e2){  //cmp=>Compare i heard like that.
    return e1.wt < e2.wt;
}

ll kruskals(vector<Edge> &input,int n,int e){
    sort(input.begin(),input.end(),cmp);  // Simple sorting

    vector<int>parent(n+1);
    vector<int>rank(n+1,1);  //DSU we have to do
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
  int edgeCount=0; //n-1 should be the edge for spanning graph
  int i=0;
  ll ans=0;

  while(edgeCount < n-1 and i<input.size()){
    Edge curr=input[i];// bcz input is sorted so we will get min wt edge.
    int srcPar=find(parent,curr.src);
    int destpar=find(parent,curr.dest);   

    if(srcPar!=destpar){
    //include edge as this will not make cycle
    Union(parent,rank,srcPar,destpar);
    ans+=curr.wt;
    edgeCount++;
    }
    i++; 
//Does not matter i picked the last edge or not, we still need to go to next edge
  }   
  return ans;
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<Edge>v(e);
    for(int i=0;i<e;i++){
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }

    cout<<kruskals(v,n,e)<<endl;
    return 0;
}