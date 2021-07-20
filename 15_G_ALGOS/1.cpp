//******************************************************************************************************************

//---------5 Algos-----------------   *****************3(SSSP)*************    -------------------------------------
//                 1.BFS                             2.Dijkistras                                     3.Bellman Ford
//             unweighted graph                     weighted graph                                     weighted graph
//             undirected graph                     undirected garph                                   directed graph
//                   --                             positive weights                                 -ve and +ve weights
//                 o(V+E)                             o(Elog(V))                                          o(EV)      
//                  o(n)                               o(nlogn)                                           o(n2)
//                   --                                 Greedy                                       *******DP******                                 

//******************************************************************************************************************

//Minimum Spanning Tree (MST):: Both are greedy algorithms::
// 1.----Kruskals Algorithm--(Greedy)---weighted-undirected
// 2.----Prims Algorithm-----(Greedy)---weighted-undirected

//******************************************************************************************************************

// Floyd warshall Algorithm :: All pair shortest path    :: DP :: o((n==V)3) :: directed graph :: adj matrix
//                          :: Works with -ve edges also :: can detect -ve cycle with one extra step ::
//                          :: *******DP******   :: space o(v2)

//*******************************************************************************************************************

#include<bits/stdc++.h>
using namespace std;
//********kruskals algorithm*******

// class DSU{
//     int *parent;
//     int *rank;
//    public:
//    DSU(int n){
//        parent = new int [n];
//        rank = new int[n];
//        for(int i=0;i<n;i++){
//            parent[i]=-1;
//            rank[i]=1;
//        }
//    }

//    int find_set(int i){
//        if(parent[i]==-1){
//           return i;
//        }
//        return parent[i] = find_set(parent[i]);
//    }

//    void unite(int x,int y){
//        int s1 = find_set(x);
//        int s2 = find_set(y);
//        if(s1!=s2){
//        if(rank[s1] < rank[s2]){
//            parent[s1]=s2;
//            rank[s2]+=rank[s1];
//        }else{
//            parent[s2]=s1;
//            rank[s1]+=rank[s2];
//        }
//        }
//    }
   
// };

// class Graph{
//     vector<vector<int>>vec;
//     int V;
//     public:
//     Graph(int V){
//         this->V=V;
//     }
//     void addEdge(int x,int y,int w){
//         vec.push_back({w,x,y});
//     }

//     int kruskals_mst(){
//         sort(vec.begin(),vec.end());
//         DSU s(V);
//         int ans = 0;
//         for(auto k:vec){
//             int w = k[0];
//             int x = k[1];
//             int y = k[2];
//             if(s.find_set(x)!=s.find_set(y)){
//                 s.unite(x,y);
//                 ans += w;
//             }
//         }
//         return ans;
//     }

// };
// int main(){
//        Graph g(4);
//        g.addEdge(0,1,1);
//        g.addEdge(1,3,3);
//        g.addEdge(3,2,4);
//        g.addEdge(2,0,2);
//        g.addEdge(0,3,2);
//        g.addEdge(1,2,2);
//        cout<<g.kruskals_mst();
// }





//********prims algorithm********
//----Mst set
//----Mst edges
//----active edges
//no sorting require so we use adjacency list not edge list representation::
// class Graph{
//    int V;
//    vector<pair<int,int>>*vec;
//    public:
//    Graph(int V){
//        this->V=V;
//       vec = new vector<pair<int,int>>[V];
//    }
//    void addEdge(int x,int y,int w){
//        vec[x].push_back({y,w});
//        vec[y].push_back({x,w});
//    }
//    int prims_mst(){
//        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >Q;
//        bool * vis = new bool[V]{0};
//        int ans = 0;
//        Q.push({0,0});
//        while(!Q.empty()){
//        auto best = Q.top();
//        Q.pop();

//        int _to = best.second;
//        int w = best.first;

//        if(vis[_to]){

//            continue;
//        }
//         ans += w;
//         vis[_to]=1;
//         for(auto x:vec[_to]){
//             if(vis[x.first]==0){
//                 Q.push({x.second,x.first});
//             }
//         }
//        }
//        return ans;
//    }
// };
// int main(){
//        Graph g(4);
//        g.addEdge(0,1,1);
//        g.addEdge(1,3,3);
//        g.addEdge(3,2,4);
//        g.addEdge(2,0,2);
//        g.addEdge(0,3,2);
//        g.addEdge(1,2,2);
//        cout<<g.prims_mst();
// }



//Bellman Ford*****************************************************************************************************************

// vector<int> Bellman_ford(int V,int src,vector<vector<int>>vec){
    
//     //craete a vector
//     vector<int> dis(V+1,INT_MAX);
//     dis[src]=0;

//     //relax all edges V-1 times
//     for(int i=0;i<V-1;i++){
//         for(auto k:vec){
//              int u = k[0];
//              int v = k[1];
//              int w = k[2];
//              if(dis[u]!=INT_MAX and dis[u] + w < dis[v]){
//                  dis[v] = dis[u] + w;
//              }
//         }
//     }
//     //negative wt cycle
//     for(auto k:vec){
//              int u = k[0];
//              int v = k[1];
//              int w = k[2];
//         if(dis[u]!=INT_MAX and dis[u] + w < dis[v]){
//                  cout<<"negative wt cycle found";
//                  exit(0);
//         }
//     }

//     return dis;
// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>>vec;
//     for(int i=0;i<m;i++){
//         int u,v,w;
//         cin>>u>>v>>w;
//         vec.push_back({u,v,w});
//     }
   
//    vector<int>dis = Bellman_ford(n,1,vec);
//    for(int i=1;i<=n;i++){
//        cout<<"Node "<<i<<" is at dis "<<dis[i]<<endl;
//    }

//     return 0;
// }

//*************************************************************************************************************************************

//  Floyd warshal ::

// vector<vector<int>> floyd_warshal(vector<vector<int>> graph){

//                     vector<vector<int>>dis(graph);
//                     int V = graph.size();

//                     // phases, in kth phase we include vertices (1,2,3,...k) as intermediate vertices :
//                     for(int k=0;k<V;k++){
//                         // iterate over entire 2D Matrix
//                         for(int i=0;i<V;i++){
//                             for(int j=0;j<V;j++){
//                             // if vertex k is included, and can we minimise the dis ?
//                             if(dis[i][j] > dis[i][k] + dis[k][j]){
//                                 dis[i][j] = dis[i][k] + dis[k][j];
//                             } 

//                             }
//                         }
//                     }
//             return dis;
// }
// #define inf 1000
// int main(){

//     //4 vertices 4 x 4 matrix 
//     vector<vector<int> > graph = {
//                                     {0,inf,-2,inf},
//                                     {4,0,3,inf},
//                                     {inf,inf,0,2},
//                                     {inf,-1,inf,0}  
//                                  };

//     auto res = floyd_warshal(graph);
//     for(int i = 0; i<res.size();i++){
//         for(int j=0;j<res.size();j++){
//             cout<<res[i][j]<<" ";
//         }cout<<endl;
//     }                             

//      return 0;                            
// }


//*******************************************************************************************************************************
