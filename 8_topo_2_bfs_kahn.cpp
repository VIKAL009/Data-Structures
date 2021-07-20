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
    }
    void Topo(){
        int *in = new int[V];
        for(int i=0;i<V;i++){
            in[i]=0;
        }
        for(int x=0;x<V;x++){
            for(auto y:l[x]){
               in[y]++;
            }
        }
        for(int i=0;i<V;i++){
            cout<<in[i]<<" ";
        }cout<<endl;
        // priority_queue<int,vector<int>,greater<int>>Q;
        queue<int>Q;
        for(int i=0;i<V;i++){
            if(in[i]==0){
               Q.push(i);
            }
        }
        while (!Q.empty())
        {
            int t=Q.front();
            // int t=Q.top();
            Q.pop();
            cout<<t<<" ";
            for(auto i:l[t]){
                in[i]--;
                if(in[i]==0){
                    Q.push(i);
                }
            }
        }   
    }
};
int main(){
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);              
    g.addEdge(2,5);
    g.Topo();
}