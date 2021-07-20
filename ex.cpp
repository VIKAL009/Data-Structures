#include<bits/stdc++.h>
using namespace std;
int tt(char b[3][3]){
    int x=0,o=0,n=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(b[i][j] == 'X') x+=1;
            else if(b[i][j] == 'O') o+=1;
            else if(b[i][j] == '_') n+=1;
        }
    }
    int wx=0,wo=0;
    if(b[0][0] == 'X' and b[0][1]=='X' and b[0][2]=='X'){
        wx=1;
    }
    if(b[1][0] == 'X' and b[1][1]=='X' and b[1][2]=='X'){
        wx=1;
    }
    if(b[2][0] == 'X' and b[2][1]=='X' and b[2][2]=='X'){
        wx=1;
    }
    if(b[0][0] == 'X' and b[1][0]=='X' and b[2][0]=='X'){
        wx=1;
    }
    if(b[0][1] == 'X' and b[1][1]=='X' and b[2][1]=='X'){
        wx=1;
    }
    if(b[0][2] == 'X' and b[1][2]=='X' and b[2][2]=='X'){
        wx=1;
    }
    if(b[0][0] == 'X' and b[1][1]=='X' and b[2][2]=='X'){
        wx=1;
    }
    if(b[0][2] == 'X' and b[1][1]=='X' and b[2][0]=='X'){
        wx=1;
    }

    if(b[0][0] == 'O' and b[0][1]=='O' and b[0][2]=='O'){
        wo=1;
    }
    if(b[1][0] == 'O' and b[1][1]=='O' and b[1][2]=='O'){
        wo=1;
    }
    if(b[2][0] == 'O' and b[2][1]=='O' and b[2][2]=='O'){
        wo=1;
    }
    if(b[0][0] == 'O' and b[1][0]=='O' and b[2][0]=='O'){
        wo=1;
    }
    if(b[0][1] == 'O' and b[1][1]=='O' and b[2][1]=='O'){
        wo=1;
    }
    if(b[0][2] == 'O' and b[1][2]=='O' and b[2][2]=='O'){
        wo=1;
    }
    if(b[0][0] == 'O' and b[1][1]=='O' and b[2][2]=='O'){
        wo=1;
    }
    if(b[0][2] == 'O' and b[1][1]=='O' and b[2][0]=='O'){
        wo=1;
    }

    if((wx==1 and wo==1) or (x-o < 0) or (x-o > 1)){
        return 3;
    }else if(x==1 and o==1 and n==9){
        return 2;
    }else if(wx==1 and wo ==0  and x>o){
        return 1;
    }else if(wx==0 and wo==1 and x==o){
        return 1;
    }else if(wx==0 and wo==0 and n==0){
        return 1;
    }else if(wx==0 and wo==0 and n>0){
        return 2;
    }else{
        return 3;
    }
}
int main(){
    int t;cin>>t;
    while (t--)
    {
       char arr[3][3];
       for(int i=0;i<3;i++){
           for(int j=0;j<3;j++){
               cin>>arr[i][j];
           }
       }
       cout<<tt(arr)<<endl;
    }
    return 0;
}