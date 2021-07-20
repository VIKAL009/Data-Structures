#include<bits/stdc++.h>
using namespace std;
vector<int>vec[10001];
int vis[10001],in[10001],low[10001],out[10001],dis[10001],subsize[10001];
   int dfs(int i){
       vis[i]=1;
       int curr_size=1;
       for(auto k:vec[i]){
           if(!vis[k]){
                curr_size+=dfs(k);
           }
       }
       subsize[i]=curr_size;
       return curr_size;
   }
int main(){
   int n,m,a,b;
   cin>>n>>m;
   for(int i=1;i<=m;i++){
       cin>>a>>b;
       vec[a].push_back(b);
       vec[b].push_back(a);
   }   
   cout<<dfs(1)<<endl;
   for(int i=1;i<=n;i++){
       cout<<subsize[i]<<" ";
   }
}