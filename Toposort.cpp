#include<bits/stdc++.h>
using namespace std;
vector<int>vec[101];
int in[101];
int vis[101];
vector<int>res;
bool kahn(int n){
    // queue<int>Q;     Max heap
    priority_queue<int,vector<int>,greater<int>>Q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
          Q.push(i);
        }
    }
    while (!Q.empty())
    {
        int curr = Q.top();
        Q.pop();
        res.push_back(curr);       
        for(auto k:vec[curr]){
           in[k]--;
           if(in[k]==0){
            Q.push(k);
           }
        }
    }
    
return res.size()==n;
}
int main(){
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        vec[a].push_back(b);
        in[b]++;
    }
    // kahn(n);
    // cout<<"Topsort:"<<endl;
    if(!kahn(n)){
          cout<<"Sandro fails."<<endl;
    }else{
    for(auto k:res){
        cout<<k<<" "<<endl;
    }
    }
}