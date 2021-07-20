//cycle detection in directed graph using DFS:
//back edge:
//stack+vis array:
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
        // l[y].push_back(x);
    }
    bool ch(int x,bool *vis,bool st[]){
            vis[x]=true;
            st[x]=true;
            for(int i:l[x]){
                if(st[i]==true){
                    return true;
                }else if(!vis[i]){
                    bool cycle_mila = ch(i,vis,st);
                    if(cycle_mila==true){
                       return true;
                    }
                }
            }


            st[x]=false;
            return false;
    }
    bool contains_cycle(){
       bool *vis = new bool[V];
       bool *st = new bool [V];
       for(int i=0;i<V;i++){
           vis[i]=false;
           st[i]=false;
       }
       return ch(0,vis,st);
    }

};
int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,5);
    g.addEdge(5,6);
    //g.addEdge(4,2); //back Edge
  
   cout<<g.contains_cycle();
}