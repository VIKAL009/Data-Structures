//Biparted graph 
//--you can divide all vertices of graph in 2 sets such that all edges of the graph are from set1 to set2 ::
//--two coloring problem :: undirected :: tree is always biparted :: and even node cyclic ::
#include<bits/stdc++.h>
using namespace std;
bool dfs_h(vector<int>graph[],int node,int vis[],int par,int color){
    vis[node]=color;
    for(auto k:graph[node]){
        if(vis[k]==0){
            int subprob = dfs_h(graph,k,vis,node,3-color);

            if(subprob==false){
                return false;
            }
        }else if(k!=par and color==vis[k]){
            return false;
        }
    }
    return true;
}
bool dfs(vector<int>graph[],int n){
    int vis[n] = {0};  // 0-not-visited  1-visited-color is 1  2-visited-color is 2
    int c=1;
   int ans = dfs_h(graph,0,vis,0,c);
   for(int i=0;i<n;i++){
       cout<<i<<" -color "<<vis[i]<<endl;
   }
   return ans;
}
int main(){
   int n,m;
   cin>>n>>m;
   vector<int>graph[n];
   while(m--){
      int x,y;
      cin>>x>>y;
      graph[x].push_back(y);
      graph[y].push_back(x);
   }
   //bfs or dfs
   if(dfs(graph,n)){
       cout<<"yes its biparted";
   }else{
       cout<<"its not";
   }

}
/*
5 4
0 1
0 2
1 3
2 4
0 -color 1
1 -color 2
2 -color 2
3 -color 1
4 -color 1
yes its biparted
*/