#include<bits/stdc++.h>
using namespace std;
vector<int>vec[2001];
int vis[2001],col[2001];
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
   int t;
   cin>>t;
   for(int tc=1;tc<=t;tc++)
   {
   int n,m,a,b;
   cin>>n>>m;
      for(int i=1;i<=n;i++) vis[i]=0,vec[i].clear();
   for(int i=1;i<=m;i++){
       cin>>a>>b;
       vec[a].push_back(b);
       vec[b].push_back(a);
   }  
   bool flag = true;
   for(int i=1;i<=n;i++){
      if(!vis[i]){
         bool res = dfs(i,0);
         if(res==false) flag =false;
      }
   }
   cout<<"Scenario #"<<tc<<":\n";
   if(flag==false){
      cout<<"Suspicious bugs found!\n";
   }else{
      cout<<"No suspicious bugs found!\n";
   }
}
}