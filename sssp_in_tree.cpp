#include<bits/stdc++.h>
using namespace std;
vector<int>vec[10001];
int vis[10001],in[10001],low[10001],out[10001],dis[10001];
   void dfs(int i,int dist){
       vis[i]=1;
       dis[i]=dist;
       for(auto k:vec[i]){
           if(!vis[k]){
                dfs(k,1+dis[i]);
           }
       }
   }
int main(){
   int n,m,a,b,q;
   cin>>n;
   for(int i=0;i<n-1;i++){
       cin>>a>>b;
       vec[a].push_back(b);
       vec[b].push_back(a);
   }
dfs(1,0);
cin>>q;
int min=INT_MAX,ans=-1;
for(int i=0;i<q;i++){
    int gc;
    cin>>gc;
    if(dis[gc]<min){
        min=dis[gc],ans=gc;
    }else
     if(dis[gc]==min&&gc<ans){
         ans=gc;
     }
}
cout<<ans;

}