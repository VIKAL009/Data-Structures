
// 1.map == array == vis
// 2.queue

#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph{
   map<T,list<T>>ls;
   public:
   void addEdge(int x,int y){
       ls[x].push_back(y);
       ls[y].push_back(x);
   }
   void bfs(T src){
       map<T,int>vis;
       queue<T>q;

       q.push(src);
       vis[src]=true;
       
       while(!q.empty()){

           T temp=q.front();
           cout<<temp<<" ";
           q.pop();

           for(auto i:ls[temp]){
               if(!vis[i]){
                   q.push(i);
                   vis[i]=true;
               }
           }
           
       }
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
    g.bfs(0);
}