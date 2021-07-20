#include<bits/stdc++.h>
using namespace std;
vector<int>vec[10001];
int timer=1;
int vis[10001],in[10001],low[10001],out[10001],dis[10001];
   void dfs(int i){
       vis[i]=1;
       in[i]=timer++;
       for(auto k:vec[i]){
           if(!vis[k]){
                dfs(k);
           }
       }
       out[i]=timer++;
   }                                            //in time of child is hiegher       out time of parent is hiegher    condition of childs lie in same sub tree
int main(){                                    //in time and out both time of 'a' id hiegher than 'b' so they are in different sub tree  for in same in(b>a) out(a>b)
   int n,m,a,b;
   cin>>n>>m;
   for(int i=1;i<=m;i++){
       cin>>a>>b;
       vec[a].push_back(b);
       vec[b].push_back(a);
   }
   dfs(1);   
   for(int i=1;i<=n;i++){
       cout<<in[i]<<" ";
   }
   cout<<"\n";
   for(int i=1;i<=n;i++){
       cout<<out[i]<<" ";
   }
}