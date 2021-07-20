//dijkstra's Algorithm : sssp(single source shortest path with weighted graph)::
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int>>>mp;

     public:
     void addEdge(T u,T v,int dis,bool bidr = true){
         mp[u].push_back({v,dis});
         if(bidr==true){
         mp[v].push_back({u,dis});
         }
     }
     void printAdj(){
          for(auto i:mp){
              cout<<i.first<<"->";
              for(auto j:i.second){
                  cout<<"("<<j.first<<","<<j.second<<") ";
              }cout<<endl;
          }
     }
     void djksssp(T src){
        unordered_map<T,int>dist;
        for(auto j:mp){
            dist[j.first]=INT_MAX;
        }

        set<pair<int,T>>st;
        dist[src]=0;
        st.insert({0,src});
        while(!st.empty()){
            auto p = *(st.begin());
            T node = p.second;
            int nodedist = p.first;
            st.erase(st.begin());
            for(auto k:mp[node]){
                if(nodedist + k.second < dist[k.first]){
                    T dest = k.first;
                    auto f = st.find({dist[dest],dest});
                    if(f!=st.end()){
                        st.erase(f);
                    }

                    dist[dest]=nodedist + k.second;
                    st.insert({dist[dest],dest});
                }
            }
        }
        for(auto i:dist){
            cout<<i.first<<" is located at distance of "<<i.second<<endl;
        }
     }

};

int main(){
    // Graph<int> g;
    // g.addEdge(1,2,1);
    // g.addEdge(1,3,4);
    // g.addEdge(2,3,1);
    // g.addEdge(3,4,2);
    // g.addEdge(1,4,7);
    // g.addEdge(1,4,7);
    // g.printAdj();
    // g.djksssp(1);

    Graph<string>india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);
    // india.printAdj();
    india.djksssp("Amritsar");


//Q.1 min[min(dis1[source_to_x]+fight[x_to_y]+dis2[y_to_dest]),dis[_when no flight]];(icpc trip):
    return 0;

}