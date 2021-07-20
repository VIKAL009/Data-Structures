#include<bits/stdc++.h>
using namespace std;
vector<int>vec[101];
int in[101],low[101],vis[101],timer;
set<int>AP;
void dfs(int x,int par){
    vis[x]=1;
    in[x]=low[x]=timer++;
    int child_count = 0;
    for(auto k:vec[x]){
        if(k==par)  continue;

        if(vis[k]==1){
            low[x]=min(low[x],in[k]);
        }else{
            dfs(k,x);
            child_count++;
            low[x]=min(low[x],low[k]);
            if((low[k]>=in[x]) && (par !=-1)){
              AP.insert(x);
            }
        }
    }
    if((par==-1)&&(child_count>1)){
        AP.insert(x);
    }
}
int main(){
   int n,m,a,b;
   while (1)
   {
       cin>>n>>m;
       if(n==0&&m==0){
           break;
       }
       for(int i=1;i<=n;i++) vec[i].clear(),vis[i]=0;
       AP.clear();
       timer=1;
       for(int i=0;i<m;i++) cin>>a>>b, vec[a].push_back(b),vec[b].push_back(a);
       for(int i=1;i<=n;i++){
           if(!vis[i]){
               dfs(i,-1);
           }
       }

       cout<<AP.size()<<endl;
   }
   
}