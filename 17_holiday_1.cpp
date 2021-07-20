//holiday accomodation - 1 concept  ::  dfs(o(v+e)) ::
#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<pair<int,int>>*ls;
    public:
    Graph(int V){
        this->V=V;
        ls = new list<pair<int,int>>[V];
    }

    void addEdge(int x,int y,int cost){
        ls[x].push_back({y,cost});
        ls[y].push_back({x,cost});
    }
    int dfs_h(int node,bool *vis,int count[],int &ans){
            vis[node]=true;
            count[node]=1;
            for(auto k:ls[node]){
                if(!vis[k.first]){
                    count[node] += dfs_h(k.first,vis,count,ans);
                     
                    int nx = count[k.first];
                    int ny = V-nx; 
                    ans += 2*min(nx,ny)*k.second;
                }
            }
            return count[node];
    }
    int dfs(){
        bool *vis = new bool[V]{false};
        int *count = new int[V]{0};
    int ans=0;
    
    cout<<dfs_h(0,vis,count,ans)<<endl; //gives size();
    return ans;
    }

};
int main(){
    Graph g(4);
    g.addEdge(0,1,3);
    g.addEdge(1,2,2);
    g.addEdge(2,3,2);
    cout<<g.dfs()<<endl;

}