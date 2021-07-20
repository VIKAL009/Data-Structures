// 1. E=V-1 and cc=1:dfs
// 2. Not Cycle and :bfs :undirected:
#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int>*l;

    public:
    Graph(int V){
        this->V=V;
        l = new list<int>[V];
    }  
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool istree(){
           bool *vis = new bool[V];
           int *par = new int [V];
           queue<int>Q;
           for(int i=0;i<V;i++){
               vis[i]=false;
               par[i]=i;
           }
           int src=0;
           Q.push(src);
           vis[src]=true;
           while (!Q.empty())
           {
               int t=Q.front();
               Q.pop();
               for(auto i:l[t]){
                   if(vis[i]==true and i!=par[t]){
                       return false;
                   }else if(!vis[i]){
                       vis[i]=true;
                       par[i]=t;
                       Q.push(i);
                   }
               }
           }
           return true;

    }

};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(3,2);
    g.addEdge(1,2);
    // g.addEdge(0,3);
  
   cout<<g.istree();
}