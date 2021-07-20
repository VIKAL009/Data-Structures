//cycle detection in undirected graph using DFS:
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
    bool ch(int x,bool *vis,int par){
            vis[x]=true;
            for(int i:l[x]){
                if(vis[i]==false){
                      bool cycle_mila = ch(i,vis,x);
                    if(cycle_mila==true){
                       return true;
                    }
                }else if(par!=i){
                   return true;
                }
            }

            return false;
    }
    bool contains_cycle(){
       bool *vis = new bool[V];
       for(int i=0;i<V;i++){
           vis[i]=false;
       }
       return ch(0,vis,0);
    }

};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    // g.addEdge(3,0);
 
 
   cout<<g.contains_cycle();
}