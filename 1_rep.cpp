#include<bits/stdc++.h>
using namespace std;
class Graph{
    // int V;
    // list<int> *ls;
    map<int,list<int>>ls;
    public:
    // Graph(int V){
    //     this->V=V;
    //     ls=new list<int>[V];
    // }
    
    void addEdge(int x,int y){
        ls[x].push_back(y);
        ls[y].push_back(x);
    }

    // void print(){
    //     for(int i=0;i<V;i++){
    //         cout<<i<<"->";
    //         for(auto k:ls[i]){
    //             cout<<k<<" ";
    //         }cout<<endl;
    //     }
    // }
    void print(){
        for(auto k:ls){
            cout<<k.first<<"->";
            for(auto j:k.second){
                cout<<j<<" ";
            }cout<<endl;
        }
    }
};
int main(){
    //  Graph g(4);
     Graph g;
     g.addEdge(0,1);
     g.addEdge(1,2);
     g.addEdge(0,2);
     g.addEdge(2,3);
     g.print();
}