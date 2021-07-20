//DAG-->directed acyclic graph:
#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph{
   map<T,list<T>>ls;
   public:
   void addEdge(T x,T y){
       ls[x].push_back(y);
    //    ls[y].push_back(x);
   }
   void dfs_h(T src,map<T,bool> & vis,list<T> &ordering){
       vis[src]=true;
       for(T i:ls[src]){
           if(!vis[i]){
               dfs_h(i,vis,ordering);
           }
       }
       ordering.push_front(src);
       return;
   }
   void dfs(){
     map<T,bool>vis;
     list<T>ordering;
     for(auto i:ls){
         vis[i.first]=false;
     }
     for(auto i:ls){
     if(!vis[i.first]){
        dfs_h(i.first,vis,ordering);
     }
     }
     for(auto i:ordering){
         cout<<i<<" ";
     }
   }

};
int main(){
    Graph<int> g;
   g.addEdge(1,2);
   g.addEdge(2,4);
   g.addEdge(1,3);
   g.addEdge(3,4);
   g.dfs();
}