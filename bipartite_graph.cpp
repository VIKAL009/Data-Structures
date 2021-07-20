#include<bits/stdc++.h>
using namespace std;
vector<int>vec[10001];
int vis[10001],in[10001],low[10001],out[10001],dis[10001],col[10001];
   bool dfs(int i,int c){
       vis[i]=1;
       col[i]=c;
       for(auto k:vec[i]){
           if(!vis[k]){
                if(dfs(k,!c)==0){     //!c    or    c^1
                    return false;
                }
                }
                else{
                    if(col[i]==col[k]){
                        return false;
                    }
                }
           }
       return true;
   }
int main(){
   int n,m,a,b;
   cin>>n>>m;
   for(int i=1;i<=m;i++){
       cin>>a>>b;
       vec[a].push_back(b);
       vec[b].push_back(a);
   }
cout<<dfs(1,0)<<"\n";  
for(int i= 1;i<=n;i++){
    cout<<col[i]<<" ";
}
}