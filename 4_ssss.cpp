#include<bits/stdc++.h>
using namespace std;
template<typename T>

// 1.distance array
// 2.queue

class Graph{
   map<T,list<T>>ls;
   public:
   void addEdge(int x,int y){
       ls[x].push_back(y);
       ls[y].push_back(x);
   }
   void bfs(T src){
       map<T,int>dis;
       queue<T>q;

       for(auto k:ls){
           dis[k.first]=INT_MAX;
       }
       q.push(src);
       dis[src]=0;
       
       while(!q.empty()){

           T temp=q.front();
           q.pop();

           for(auto i:ls[temp]){
               if(dis[i]==INT_MAX){
                   q.push(i);
                   dis[i]=dis[temp]+1;
               }
           }
       }
       for(auto i:ls){
           cout<<i.first<<" -> "<<dis[i.first]<<endl;
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