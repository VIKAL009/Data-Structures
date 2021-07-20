//DP with Bitmasking : Travelling Salesman problem (2-D DP)::
//Also called hamiltonian cycle 
//top-down   rec + memo

#include<bits/stdc++.h>
using namespace std;
int t[16][4];
int n=4;
  // adj matrix
int dis[4][4] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}        
  };
int vis_all = (1<<n)-1;

int tsp(int mask,int pos){
    if(mask==vis_all){
        return dis[pos][0];
    }
    int ans = INT_MAX;
    if(t[mask][pos]!=0){
        return t[mask][pos];
    }
    for(int city=0;city<n;city++){
         if((mask & (1<<city) )== 0){
             int newans = dis[pos][city]  + tsp((mask | (1<<city)),city);
             ans = min(ans,newans);  
         }
    }
    return t[mask][pos] = ans;
}

int main(){
    cout<<tsp(1,0)<<endl;
}
//  o(2^n x n) instead of n-1 fact.
