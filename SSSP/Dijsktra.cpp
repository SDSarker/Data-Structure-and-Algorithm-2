#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        //{dist,node}
        vector<vector<pair<int,int>>> adj(V);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
        vector<int> dist(V,1e9);
        dist[src]=0;
        Q.push({0,src});
        while(!Q.empty()){
            int weight=Q.top().first;
            int node=Q.top().second;
            Q.pop();
            for(auto i:adj[node]){
                
                int v=i.first;
                int w=i.second;
                if(weight+w<dist[v] ){
                    
                    dist[v]=weight+w;
                    Q.push({dist[v],v});
                }
                
            }
        }
        return dist;
    }
};