#include <bits/stdc++.h>
using namespace std;

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

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> cord(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        cord[i]={x,y};
    }
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    for(int i=0;i<n-1;i++){
        //cout<<i<<" : ";
        for(int j=i+1;j<n;j++){
            int dist=abs(cord[i].first-cord[j].first)+abs(cord[i].second-cord[j].second);
            pq.push({dist,i,j});
            //cout<<dist<<" ";
        }
        //cout<<endl;
    }
    Disjoint ds(n);
    int cost=0;
    while(!pq.empty()){
        int u=pq.top()[1];
        int v=pq.top()[2];
        int w=pq.top()[0];
        pq.pop();
        if(ds.findPar(u)!=ds.findPar(v)){
            cost+=w;
            ds.unionByRank(u,v);
        }
    }

    cout<<cost<<endl;
}