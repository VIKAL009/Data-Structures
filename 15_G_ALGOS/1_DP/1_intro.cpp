#include<bits/stdc++.h>
using namespace std;
//DP----> optimal substructure  ----> overlapping problem :: tabular (bottom-up) ::memoization is top-down::
//0.only recursive ::
//1.top-down---------------------------------------------o(n)--from 2^n----space--o(n)

// int fib(int n,int dp[]){
//     if(n<=1){
//         return n;
//     }
//     if(dp[n]!=0){
//         return dp[n];
//     }
//     return dp[n] = fib(n-1,dp)+fib(n-2,dp);
// }
// int main(){
//     int n;
//     cin>>n;
//     int dp[n+1]{0};
//     cout<<fib(n,dp);
// }

//2.bottom-up----------------------------------------------o(n)--from 2^n----space--o(n)

// int fib(int n){
//     int dp[n+1]{0};
//     dp[1]=1;
//     for(int i=2;i<=n;i++){
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n];
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<fib(n);
// }

//3.bottom-up----------------------------------------------o(n)--from 2^n----space--o(1)---space optimization

// int spaceopt(int n){
//     if(n<=1){
//         return n;
//     }
//     int a=0;
//     int b=1;
//     int c;
//     for(int i=2;i<=n;i++){
//         c=a+b;
//         // cout<<c<<" ";
//         a=b;
//         b=c;
//     }
//     return c;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<spaceopt(n);
// }

//4.Matrix exponentiation ::--------------------------------------------------------------------------------------------------------------------------------------------


//minimum steps to 1-------------------o(n)--------------------------------------------------------top-down-
// int minsteps(int n,int dp[]){
//     if(n==1){
//         return 0;
//     }
//     if(dp[n]!=0){
//         return dp[n];
//     }
//     int op1=INT_MAX;
//     int op2=INT_MAX;
//     int op3=INT_MAX;
//     if(n%2==0){
//         op1 = minsteps(n/2,dp)+1;
//     }
//     if(n%3==0){
//         op2 = minsteps(n/3,dp)+1;
//     }

//         op3 = minsteps(n-1,dp)+1;

//      int ans = min(op1,min(op2,op3));
//      return dp[n] =ans;
// }
// int main(){
//   int n;
//   cin>>n;
//   int dp[n+1]{0};
//   cout<<minsteps(n,dp);
// }
//minimum steps to 1-------------------o(n)--------------------------------------------------------bottom-up-
// int minsteps(int n,int dp[]){
//    dp[1]=0;
//    int op1,op2,op3;
//    op1 = op2 = op3 = INT_MAX;
//    for(int i=2;i<=n;i++){
//    if(n%2==0){
//        op1 = dp[i/2];
//       }
//    if(n%3==0){
//        op2 = dp[i/3];
//       }
//    op3 = dp[i-1];
//    dp[i]= min(op1,min(op2,op3))+1;
//    }
//    return dp[n];
// }
// int main(){
//   int n;
//   cin>>n;
//   int dp[n+1]{0};
//   cout<<minsteps(n,dp);
// }
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

//minimmum coin change problem :: o(NT) ::
//top-down
// int coins(int N,int dp[],int T,int coin[]){
//     if(N==0){
//         return 0;
//     }
//     if(dp[N]!=0){
//         return dp[N];
//     }
//     int ans =INT_MAX;
//     for(int i=0;i<T;i++){
//         if(N-coin[i] >=0 ){
//             int subprob = coins(N-coin[i],dp,T,coin);
//             ans = min(ans,subprob+1);
//         }
//     }
//     return dp[N] = ans;
// }
// int main(){
//     int N=15;
//     int coin[]={1,7,10};
//     int T=3;
//     int dp[N+1]{0};
//     cout<<coins(N,dp,T,coin);
// }


//bottom-up
int coins(int N,int dp[],int T,int coin[]){
    for(int n=1;n<=N;n++){
        dp[n]=INT_MAX;
        for(int t=0;t<T;t++){
            if(n-coin[t] >=0 ){
                int subprob = dp[n-coin[t]];
                dp[n] = min(dp[n],subprob+1);
           }
        }
    }
    return dp[N];
}
int main(){
    int N=15;
    int coin[]={1,7,10};
    int T=3;
    int dp[N+1]{0};
    cout<<coins(N,dp,T,coin);
}


