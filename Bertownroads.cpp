#include<bits/stdc++.h>
using namespace std;
vector<int>vec[100001];
int in[100001],vis[100001],low[100001],timer;
bool hasbridge;
vector<pair<int,int>>edgeList;
void dfs(int x,int par){
    vis[x]=1;
    in[x]=low[x]=timer++;
    for(auto k:vec[x]){
        if(k==par){
            continue;
        }
        if(vis[k]==1){
            low[x]=min(low[x],in[k]);
            if(in[x]>in[k]){
                edgeList.push_back({x,k});
            }
        }
        else{
                dfs(k,x);
                if(low[k]>in[x]){
                    hasbridge=true;
                    return;
                }
                edgeList.push_back({x,k});
                low[x]=min(low[x],low[k]);
        }
    }
}
int main(){
     int n,m,a,b;
     cin>>n>>m;
     while (m--)
     {
         cin>>a>>b, vec[a].push_back(b),vec[b].push_back(a);
     }
     
     dfs(1,-1);
     if(hasbridge){
         cout<<0;
     }else{
         for(pair<int,int> z:edgeList){
             cout<<z.first<<" "<<z.second<<"\n";
         }
     }
}