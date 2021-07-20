#include<bits/stdc++.h>
using namespace std;
template<typename T>

// vis array

class Graph{
   map<T,list<T>>ls;
   public:
   void addEdge(int x,int y){
       ls[x].push_back(y);
       ls[y].push_back(x);
   }
   void dfs_h(T src,map<T,bool> & vis){
       cout<<src<<" ";
       vis[src]=true;
       for(auto i:ls[src]){
           if(!vis[i]){
               dfs_h(i,vis);
           }
       }
   }
   void dfs(T src){
     map<T,bool>vis;
    //  for(auto i:ls){
    //      vis[i.first]=false;
    //  }
     dfs_h(src,vis);
   }

};
int main(){
    Graph<int> g;
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(1,0);
    g.addEdge(3,0);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.dfs(0);
}