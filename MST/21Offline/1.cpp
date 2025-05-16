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


vector<vector<int>> KruskalSpanning(int V, vector<vector<int>> edges){
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // w,u,v

    for (auto i:edges)
    {
        int u=i[0];
        int v=i[1];
        int w=i[2];
        pq.push({w,u,v});
    }

    vector<vector<int>> ans;
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
            ans.push_back({u,v,w});
        }
    }

    return ans;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int a,b ,w;
        cin>>a>>b>>w;
        edges.push_back({a,b,w});
    }

    vector<vector<int>> res=KruskalSpanning(n,edges);
    for(auto i:res){
        cout<<"["<<i[0]<<","<<i[1]<<","<<i[2]<<"], ";
    }
    cout<<" ";

}