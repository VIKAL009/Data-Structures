#include<bits/stdc++.h>
using namespace std;
vector<int>vec[10001];
int vis[10001],in[10001],low[10001],out[10001],dis[10001];
   void dfs(int i){
       vis[i]=1;
    //    cout<<i<<"->";
       for(auto k:vec[i]){
           if(!vis[k]){
                dfs(k);
           }
       }
   }
int main(){
   int n,m,a,b;
   cin>>n>>m;
   for(int i=1;i<=m;i++){
       cin>>a>>b;
       vec[a].push_back(b);
       vec[b].push_back(a);
   }
//    dfs(1);

   int _cc=0;
   for(int i=1;i<=n;i++){
       if(!vis[i]){
           dfs(i), _cc++;
       }
   }
//    cout<<_cc;
if(_cc==1&&m==n-1){
    cout<<"YES";
}else{
    cout<<"NO";
}

   
}