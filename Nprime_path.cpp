#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>vec[100001];
ll vis[100001],dis[100001];
vector<ll>primes;
bool isvalid(ll a,ll b){
    ll cnt=0;
    while (a>0)
    {
        if((a%10)!=(b%10)) {
            cnt++;
        }

        a/=10,   b/=10;
    }
    if(cnt==1){  
    return true;
    }
    else{
     return false;
    }    
    
}
bool isprime(ll n){
    for(ll i=2;i*i<n;i++){
        if(n%i==0) return false;
    }

    return true;
}
void graph(){
     for(ll i=1000;i<=9999;i++){
         if(isprime(i)){
           primes.push_back(i);
         }
     }
     for(ll i=0;i<primes.size();i++){
         for(int j=i+1;j<primes.size();j++){
            int a=primes[i];
            int b=primes[j];
            if(isvalid(a,b)){
                vec[a].push_back(b);vec[b].push_back(a);
            }
         }
     }
}
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
                  vis[i]=1;
                  dis[i]=dis[temp]+1;
                  Q.push(i);
              }
          }
      }
      
  }
int main(){
    ll t,a,b;
    cin>>t;
    graph();
    while (t--)
    {
        cin>>a>>b;
        for(ll i=1000;i<=9999;i++) dis[i]=-1,vis[i]=0;


        bfs(a);


        if(dis[b]==-1){
            cout<<"Impossible"<<endl;
        }else{
            cout<<dis[b]<<endl;
        }
    }
    

}