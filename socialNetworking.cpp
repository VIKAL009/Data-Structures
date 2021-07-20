#include<bits/stdc++.h>
using namespace std;
vector<int>vec[1000001];
int vis[1000001],dist[1000001],level[1000001];
void bfs(int x){
    queue<int>Q;
    vis[x]=1;
    dist[x]=0;
    Q.push(x);
    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        for(auto k:vec[curr]){
            if(!vis[k]){
                vis[k]=1;
                Q.push(k);
                dist[k]=dist[curr]+1;
                level[dist[k]]++;
            }
        }
    }
}
int main(){
  int n,m,a,b,d,src,q;
  cin>>n>>m;
  for(int i=0;i<m;i++){
      cin>>a>>b;
      vec[a].push_back(b);
      vec[b].push_back(a);
  }
  cin>>q;
  while (q--)
  {
      cin>>src>>d;
      for(int i=0;i<=n;i++){
          level[i]=0;vis[i]=0;       //dist[i]=0; optional because overwritten:
      }
      bfs(src);
      cout<<level[d]<<endl;
  }
}