#include<bits/stdc++.h>
using namespace std;
vector<int>vec[101];
int in[101],low[101],vis[101];
int timer;
void dfs(int x,int par){
    vis[x]=1;
    in[x]=low[x]=timer;
    timer++;
    for(auto k:vec[x]){

        if(k==par) continue;

        if(vis[k]==1)
        {
                      //node->child - back edge
                      low[x]=min(low[x],in[k]);
        }
        else
        {
                      //node->child - forward edge
                      dfs(k,x);
                      if(low[k]>in[x]){
                          cout<<x<<" - "<<k<<" is a bridge\n";
                      }
                           low[x]=min(low[x],low[k]);
        }
    }
}
int main(){
  int n,m,x,y;
  cin>>n>>m;
  while (m--)
  {
      cin>>x>>y,vec[x].push_back(y),vec[y].push_back(x);
  }
  dfs(1,-1);
}