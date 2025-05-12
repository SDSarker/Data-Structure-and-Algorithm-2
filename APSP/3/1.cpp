#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &dist,int n) {
    // Code here
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]==1e8||dist[k][j]==1e8) continue;
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                }
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dist(n+1,vector<int>(n+1,1e8));
    
    for(int i=1;i<=n;i++){
        
            dist[i][i]=0;
    }

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
        dist[v][u]=w;
    }
    

    floydWarshall(dist,n);
    for(int i=1;i<=n;i++){
        if(dist[i][i]!=0){
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;
    return 0;
}