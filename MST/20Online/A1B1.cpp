#include<bits/stdc++.h>
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


int KruskalSpanning(int V, vector<vector<int>> edges){
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // w,u,v

    for (auto i:edges)
    {
        int u=i[0];
        int v=i[1];
        int w=i[2];
        pq.push({w,u,v});
    }

    int cost=0;
    Disjoint dis(V);
    while (!pq.empty())
    {
        int w = pq.top()[0];
        int u = pq.top()[1];
        int v = pq.top()[2];
        pq.pop();
        if (dis.findPar(u) != dis.findPar(v))
        {
            dis.unionByRank(u, v);
            cost+=w;
        }
    }

    return cost;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> cord;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        cord.push_back({x,y});
    }
    vector<vector<int>> edges;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int dist=abs(cord[i][0]-cord[j][0])+abs(cord[i][1]-cord[j][1]);
            edges.push_back({i,j,dist});
        }
    }

    int ans=KruskalSpanning(n,edges);
    cout<<ans<<endl;
}