//strongly connected components :: SCC
//kosaraju's;
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>graph[],int i,bool vis[],vector<int>&st){
    vis[i]=true;
    for(auto k:graph[i]){
        if(!vis[k]){
            dfs(graph,k,vis,st);
        }
    }
    st.push_back(i);
}
void dfs2(vector<int>graph[],int i,bool vis[]){
    vis[i]=true;
    cout<<i<<" ";
    for(auto k:graph[i]){
        if(!vis[k]){
            dfs2(graph,k,vis);
        }
    }
}
void solve(vector<int>graph[],vector<int>rev_graph[],int n){
    bool vis[n];
    memset(vis,0,n);
    vector<int>st;
    // 1.store acc. to out time:
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(graph,i,vis,st);
        }
    }
    //ordering st:
    //2.reveres
    //3. dfs acc. to ordering
    memset(vis,0,n);
    char comp = 'A';
    for(int x=st.size()-1;x>=0;x--){
        if(!vis[st[x]]){
            cout<<"Component "<<comp<<"-->";
            dfs2(rev_graph,st[x],vis);
            cout<<endl;
            comp++;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>graph[n];
    vector<int>rev_graph[n];
    int m;
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }
    solve(graph,rev_graph,n);
}
/*
7 8
2 1
1 0
0 2
0 3
3 5
5 6
6 3
3 4
Component A-->0 1 2 
Component B-->3 6 5
Component C-->4
*/