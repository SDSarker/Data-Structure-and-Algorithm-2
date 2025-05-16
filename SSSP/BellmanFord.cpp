#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src]=0;
        for(int j=0;j<V-1;j++){
            for(auto i:edges){
                int u=i[0];
                int v=i[1];
                int w=i[2];
                if(dist[u]!=1e8 && (dist[u]+w) <dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
        
        
        for(auto  i: edges){
            int u=i[0];
            int v=i[1];
            int w=i[2];
            if(dist[u]!=1e8 && dist[u]+w<dist[v]){
                return {-1};
            }
        }
        
        return dist;
        
    }
};