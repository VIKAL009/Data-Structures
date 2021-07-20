#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
vector<int>vec[100001];
int vis[100001];
long long ct;
   void dfs(int i){
       vis[i]=1;
       ct++;
       for(auto k:vec[i]){
           if(!vis[k]){
                dfs(k);
           }
       }
   }
int main(){
    int t;
    cin>>t;
    while (t--)
    { 
   long long n,m,a,b;
   cin>>n>>m;
   for(long long i=1;i<=n;i++) vec[i].clear(),vis[i]=0;
   for(long long i=1;i<=m;i++){
       cin>>a>>b;
       vec[a].push_back(b);
       vec[b].push_back(a);
   }
   long long _cc=0;
   long long res =1;
   for(long long i=1;i<=n;i++){
       if(!vis[i]){
           ct=0;
           dfs(i);
           _cc++;
          res = (res*ct)%mod;
       }
      }
    cout<<_cc<<" "<<res<<"\n"; 
    }
    // cout<<mod;
}