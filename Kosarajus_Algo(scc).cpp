#include<bits/stdc++.h>                      //1.Ci<---Cj     out[c_i]>cout[c_j] . 
using namespace std;                         //2.DAG  has at least 1 node with in_degree 0   that has out_degree 0 intransposed graph.
vector<int>vec[1001];                        //3.graph and transposed graph has same SCC(strongly connected components).
vector<int>tr[1001];                         //4.Acyclic property of condendeg graph.
vector<int>order;
vector<int>scc;
int vis[1001];
void dfs(int k){
    vis[k]=1;
    for(auto i:vec[k]){
        if(!vis[i]){
            dfs(i);
        }
    }
    order.push_back(k);
}
void dfs1(int k){
    vis[k]=1;
    for(auto i:tr[k]){
        if(!vis[i]){
            dfs1(i);
        }
    }
    scc.push_back(k);
}
int main(){ 
    int n,m,a,b,t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++) tr[i].clear(), vec[i].clear(),vis[i]=0;

        order.clear();
        
        for(int i=0;i<m;i++){
            cin>>a>>b;
            vec[a].push_back(b);
            tr[b].push_back(a);
        }

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i);
            }
        }

        for(int i=1;i<=n;i++){
               vis[i]=0;
        }
        for(int i=1;i<=n;i++){
            if(!vis[order[n-i]]){
               scc.clear();
               dfs1(order[n-i]);

               cout<<"dfs1() called from "<<order[n-i]<<" and printing SCC"<<endl;
               for(auto z:scc){
                   cout<<z<<" ";
               }
                   cout<<endl;
            }
        }
    }
    
}