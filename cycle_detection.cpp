#include<bits/stdc++.h>
using namespace std;
vector<int>vec[10001];
int vis[10001],in[10001],low[10001],out[10001],dis[10001];
   bool dfs(int i,int par){
       vis[i]=1;
       for(auto k:vec[i]){
           if(!vis[k]){
                if(dfs(k,i)==true) return true;
           }else if(k!=par)
           {
               return true;
           }
       }
       return false;
   }
int main(){
   int n,m,a,b;
   cin>>n>>m;
   for(int i=1;i<=m;i++){
       cin>>a>>b;
       vec[a].push_back(b);
       vec[b].push_back(a);
   }
   if(dfs(1,-1)){
       cout<<"Cicle is present :";
   }else{
       cout<<"cycle is not present:";
   }
   
}