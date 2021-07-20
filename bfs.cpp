#include<bits/stdc++.h>
using namespace std;
vector<int>vec[10001];
int vis[10001],dis[10001];
  void bfs(int x){
      queue<int>Q;
      Q.push(x);
      vis[x]=1;
      dis[x]=0;
      while (!Q.empty())
      {
          int temp = Q.front();
          Q.pop();
          for(auto i:vec[temp]){
              if(!vis[i]){
                  Q.push(i);
                  dis[i]=dis[temp]+1;
                  vis[i]=1;
              }
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
   bfs(1);
   cout<<dis[n]<<"\n"; 
   for(int i=1;i<=n;i++){
       cout<<dis[i]<<" ";
   }  
}