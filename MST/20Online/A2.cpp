#include <bits/stdc++.h>
using namespace std;

//Pari nai eta
//Parle solution dis

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
    int n,m;
    
    cin>>n>>m;
    priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>> pq;   //w,u,v
    for(int i=0;i<m;i++){
        int u,v;
        double d;
        cin>>u>>v>>d;
        pq.push({-log(d),{u,v}});
    }

    double cost=0;
    Disjoint ds(n);
    while (!pq.empty())
    {
        double w = pq.top().first;
        int u = pq.top().second[0];
        int v = pq.top().second[1];
        pq.pop();
        if (ds.findPar(u) != ds.findPar(v))
        {
            ds.unionByRank(u, v);
            cost+=w;
        }
    }

    
    double res=pow(2.7182818,-cost);
    cout<<res<<endl;

}