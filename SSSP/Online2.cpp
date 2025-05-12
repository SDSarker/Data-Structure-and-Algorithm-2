#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    vector<int> tax(N+1);
    for(int i=1;i<=N;i++){
        int t;
        cin>>t;
        tax[i]=t;
    }
    vector<vector<int>> adj(N+1);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> cost(N+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;  //cost,node
    Q.push({0,1});
    cost[1]=0;
    while(!Q.empty()){
        int cur_cost=Q.top().first;
        int u=Q.top().second;
        Q.pop();
        for(auto i:adj[u]){
            if(cur_cost+tax[i]<cost[i]){
                cost[i]=cur_cost+tax[i];
                Q.push({cost[i],i});
            }
        }
    }

    cout<< cost[N];
}