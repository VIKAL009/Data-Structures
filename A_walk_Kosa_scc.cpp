#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
 
using namespace std;
vi graph[100001];
vi revG[100001];
vi scc , order;
int vis[100001];
int ans[100001];
 
void dfs(int node)
{
	vis[node] = 1;
	for(int v : graph[node])
	{
		if(vis[v] == false) dfs(v);
	}
	
	order.pb(node);
}
 
void dfs1(int node)
{
	scc.pb(node);
	vis[node] = 1;
	for(int v : revG[node])
	{
		if(vis[v] == false) dfs1(v);
	}
}
 
void updateAnswer()
{
	if(scc.size() <= 1) return;
	
	for(int node : scc) ans[node] = 1;
}
 
int main()
{
	int n , m , a, b;
	cin>>n>>m;
	
	REP(i , m) cin>>a>>b , graph[a].pb(b) , revG[b].pb(a);
	
	REP(i , n)
	{
		if(vis[i] == 0) dfs(i);
	}
	
	reverse(order.begin() , order.end());
	REP(i , n) vis[i] = 0;
	
	for(int node : order)
	{
		if(vis[node] == false)
		{
			scc.clear();
			dfs1(node);
			updateAnswer();
		}
	}
	
	REP(i , n) cout<<ans[i]<<" ";
}
 