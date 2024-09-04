 // DSU->Disjoint Set Union  OR Union find algorithm/data structure.

//  CLUSTERING / GROUPING -> You will be have some elements and you 
//  need to add them or segeregate them in different groups/elements.
//  And sometimes we might need to identify the group any element it 
 // belongs to thats whu we use disjoint st union.

 //   Means if i ask that a,b,c,d.....f,g,h.
 //  We can group them in two groups like(group 1) a,b,d and (group 2)c,e,f.

   
 //  leader/parent of the group->koi ek element ko us group ko randomly le lenge taki us group ko identify kiya jaa sake.
 //  jo leader us group ka ban jayega use use us group ka group of a,b etc kahenge.


//  What function DSU need to support ?

// (1)  Union(a,b)->Adds the graph where element b belongs to the graph
//  where element A belongs to or vice-versa.
 
// Union(1,5)->  (1,3)   (2,,5,7) union is 1,3,2,5,7.

// (2) find (x)/get(x):-> This will be used to find which group x belongs to.
// We will return the parent of the group that x belongs to.
      
//       (2,3,1,6)->Part (3),    get (2)=3, get(3)=3


// Approach 1-> Represent every group as a set.
// where i will join the evert groups but its co plexity is bad as a prespective of interview


// Approach 2-> By using array. 
//  We will use array to represent the group.Where index represent the actual element 
// and value represent the the grouping of the elements. 23:43 


// Find operation in DSU will be order of(n) in term of time complexity.

// Union operation in DSU will be order of (n) in term of time complexity.




#include<iostream>
#include<vector>
using namespace std;

int find(vector<int>&parent,int x){
      //This methods returns which group/cluster x belongs to.
      return parent[x]=(parent[x]=x)?x:find(parent,parent[x]);
}
void Union(vector<int>&parent,vector<int>&rank,int a, int b){
      a=find(parent,a);
      b=find(parent,b);

      if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b]=a;
      }
      else{
            rank[b]++;
            parent[a]=b;
      }
}

int main(){
      int n,m;
      cin>>n>>m;
     // n->Numbers of elements,m->Number of queries
      vector<int>parent(n+1);
      vector<int>rank(n+1,0);
      for(int i=0;i<=n;i++){
            parent[i]=i;
      }
      while(m--){
            string str;
            cin>>str;
            if(str=="union"){
                  int x,y;
                  cin>>x>>y;
             Union(parent,rank,x,y);
            }
            else{
                  int x;
                  cin>>x;
                  cout<<find(parent,x)<<"\n";
            }
      }
}

 Input

5
8
union
1 2
union
2 3
union
1 4
find
1 (for 1 i am finding)
1  (Output)
find
2 (for 1 i am finding)
2 (There should be 1 instead of 2.)




// //   Below one belongs to the ChatGPT 

// #include<iostream>
// #include<vector>
// using namespace std;

// int find(vector<int>& parent, int x) {
//     // Find the root of the set containing x, with path compression.
//     if (parent[x] != x) {
//         parent[x] = find(parent, parent[x]);
//     }
//     return parent[x];
// }

// void Union(vector<int>& parent, vector<int>& rank, int a, int b) {
//     a = find(parent, a);
//     b = find(parent, b);

//     if (a != b) {  // Union only if they are in different sets.
//         if (rank[a] > rank[b]) {
//             parent[b] = a;
//         } else if (rank[a] < rank[b]) {
//             parent[a] = b;
//         } else {
//             parent[b] = a;
//             rank[a]++;
//         }
//     }
// }

// int main() {
//     int n, m;
//     cout<<"Enter n"<<endl;
//      cin >> n;
//     cout<<"Enter m"<<endl;
//     cin >> m;
//     // n -> Number of elements, m -> Number of queries
//     vector<int> parent(n + 1);
//     vector<int> rank(n + 1, 0);
    
//     for (int i = 1; i <= n; i++) {
//         parent[i] = i;
//     }

//     while (m--) {
//         string str;
//         cin >> str;
//         if (str == "union") {
//             int x, y;
//             cin >> x >> y;
//             Union(parent, rank, x, y);
//         } else if (str == "find") {
//             int x;
//             cin >> x;
//             cout << find(parent, x) << "\n";
//         }
//     }

//     return 0;
// }
 Input

5
8
union
1 2
union
2 3
union
1 4
find
1 (for 1 i am finding)
1  (Output)
find
2 (for 1 i am finding)
1  (Output)