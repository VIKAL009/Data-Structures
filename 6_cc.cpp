#include<bits/stdc++.h>
using namespace std;
template<typename T>

 //dfs

class Graph{
   map<T,list<T>>ls;
   public:
   void addEdge(T x,T y){
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
   void dfs(){
     map<T,bool>vis;
     for(auto i:ls){
         vis[i.first]=false;
     }
     int c=0;
     for(auto i:ls){
        if(!vis[i.first]){
        cout<<"Component "<<c<<"-->";
        dfs_h(i.first,vis);
        c++;
        cout<<endl;
        }
     }
   }

};
int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(8,8);
    g.dfs();
}