#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>vec[10001];
int vis[10001],maxd,maxnode;
void dfs(int x,int d){
     vis[x]=1;
     if(d>maxd) maxd=d,maxnode=x;
     for(auto i:vec[x]){
         if(!vis[i]){
             dfs(i,d+1);
         }
     }
}
int main(){
int n,a,b;
cin>>n;
for(int i=1;i<=n-1;i++){
    cin>>a>>b;
    vec[a].push_back(b),vec[b].push_back(a);
}
maxd=-1;
dfs(1,0);
for(int i=0;i<=n;i++) {
    vis[i]=0;       
    } //key
maxd=-1;
dfs(maxnode,0);
cout<<maxd<<"\n";
}