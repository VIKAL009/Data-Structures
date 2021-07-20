//Disjoint Union Set / Union - Find
//*********************************
// --Union(s1,s2);
// --find(element);

//Edge list representation: cycle detection
#include<bits/stdc++.h>
using namespace std;
class Graph{
   int V;
   list<pair<int,int>>ls;
   public:
   Graph(int V){
       this->V=V;
   }
   void addEdge(int u,int v){
      ls.push_back({u,v});
   }
   int find_set(int i,int parent[]){
        if(parent[i]==-1){
            return i;
        }

        return parent[i] = find_set(parent[i],parent);
   }
   void union_set(int x,int y,int parent[],int *rank){
        int s1 = find_set(x,parent);
        int s2 = find_set(y,parent);
        if(s1!=s2){
            // parent[s1]=s2;
            // parent[s2]=s1;

            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }else
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
            
        }
   }
   bool contain_cycle(){
      int *par = new int [V];
      int *rank = new int [V];
      for(int i=0;i<V;i++){
          par[i]=-1;
          rank[i]=1;
      }
      for(auto i:ls){
          int s1 = find_set(i.first,par);
          int s2 = find_set(i.second,par);
          if(s1!=s2){
              union_set(s1,s2,par,rank);
          }
          else
          {
              cout<<"Same parent "<<s1<<" and "<<s2<<endl;
              return true;
          }      
      }

    //   cout<<endl;
    //   for(int i=0;i<V;i++){
    //       cout<<par[i]<<" ";
    //   }
    //   cout<<endl;
    //   for(int i=0;i<V;i++){
    //       cout<<rank[i]<<" ";
    //   }
    //   cout<<endl;

   delete [] par;
   delete [] rank;
   return false;
   }
   int pairing(){
        int *par = new int [V];
      int *rank = new int [V];
      for(int i=0;i<V;i++){
          par[i]=-1;
          rank[i]=1;
      }
      int ans=0;
      for(auto k:ls){
          int i = k.first;
          int j = k.second;

          int s1 = find_set(i,par);
          int s2 = find_set(j,par);

          union_set(s1,s2,par,rank);
      }

      //go to all nodes
      for(int i=0;i<V;i++){
          ans += V - rank [find_set(i,par)];
      }
      delete [] par;
      delete [] rank;
      return ans/2;
   }
};
int main(){
//    Graph g(4);
//    g.addEdge(0,1);
//    g.addEdge(1,2);
//    g.addEdge(2,3);
//    g.addEdge(3,0);
//    cout<<g.contain_cycle();

   Graph g(5);
   g.addEdge(0,1);
   g.addEdge(1,4);
   g.addEdge(2,3);
   cout<<g.pairing();
}


//optimisations***
//1.path compression optimisation in DSU (find fn): 
// return find_set(parent[i],parent);  -->  return parent[i] = find_set(parent[i],parent);

//2.union by rank (union fn):

//             if(rank[s1]<rank[s2]){
//                 parent[s1]=s2;
//                 rank[s2]+=rank[s1];
//             }else
//             {
//                 parent[s2]=s1;
//                 rank[s1]+=rank[s2];
//             }