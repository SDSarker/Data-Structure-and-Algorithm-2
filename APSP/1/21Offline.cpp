#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>(n+1,1e9));
    // vector<vector<int>> par(n+1,vector<int>(n+1,-1));
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u][v]=w;
        adj[v][u]=w;
    }
    int t;
    cin>>t;

    for(int i=1;i<n+1;i++){
        adj[i][i]=0;
    }


    for(int k=1;k<n+1;k++){
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    // for(int i=1;i<n+1;i++){
    //     for(int j=1;j<n+1;j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    vector<int> reachable(n+1,0);
    int minimum=1e9;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(i!=j && adj[i][j]<=t){
                reachable[i]++;
            }
        }
        minimum=min(reachable[i],minimum);
    }

    for(int i=1;i<n+1;i++){
        if(minimum==reachable[i]) cout<<i<<" ";
    }
}