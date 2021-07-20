#include<bits/stdc++.h>
using namespace std;
class Graph{
   unordered_map<string ,list<pair<string ,int>>> ls;
   public:

   void addEdge(string x,string y,bool bidr,int dis){
          ls[x].push_back(make_pair(y,dis));
          if(bidr){
          ls[y].push_back(make_pair(x,dis));
          }
   }
   void print(){
       for(auto i:ls){
          string city=i.first;
          list<pair<string,int>>k=i.second;
          cout<<city<<"->";
          for(auto j:k){
              cout<<j.first<<" "<<j.second<<",";
          }cout<<endl;
       }
   }

    
};
int main(){
     Graph g;
     g.addEdge("A","B",true,20);
     g.addEdge("B","D",true,40);
     g.addEdge("A","C",true,10);
     g.addEdge("A","D",false,50);
     g.addEdge("C","D",true,40);
     g.print();
}