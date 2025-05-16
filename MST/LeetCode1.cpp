//https://leetcode.com/problems/number-of-operations-to-make-network-connected/


#include<bits/stdc++.h>
using namespace std;

class Solution {
class Disjoint{
    vector<int> parent;
    vector<int> rank;

    public:
    Disjoint(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findPar(int x){
        if(parent[x]==x){
            return x;
        }

        return parent[x]=findPar(parent[x]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};


public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        priority_queue<vector<int>> pq;
        Disjoint ds(n);
        int extra=0;
        for(auto i: connections){
            if(ds.findPar(i[0])==ds.findPar(i[1])) extra++;
            else{
                ds.unionByRank(i[0],i[1]);
            }
        }

        int comp=0;
        for(int i=0;i<n;i++){
            if(ds.findPar(i)==i) comp++;
        }

        if(comp-1>extra) return -1;
        return comp-1;
    }
};