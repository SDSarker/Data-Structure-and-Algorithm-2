#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &dist,vector<vector<int>> &parent,int n) {
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]==1e8||dist[k][j]==1e8) continue;
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    parent[i][j]=parent[k][j];
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
    vector<vector<int>> parent(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        
            dist[i][i]=0;
    }

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
        parent[u][v]=u;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(parent[i][j]==0) cout<<"Nil"<<" ";
            else cout<<parent[i][j]<<" ";
        }
        cout<<endl;
    }

    floydWarshall(dist,parent,n);
    cout<<"Shortest distance matrix:"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==1e8) cout<<"Inf"<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(parent[i][j]==0) cout<<"Nil"<<" ";
            else cout<<parent[i][j]<<" ";
        }
        cout<<endl;
    }
}

// 5 9
// 1 2 3
// 1 3 8
// 1 5 -4
// 2 5 7
// 2 4 1
// 4 1 2
// 5 4 6
// 4 3 -5
// 3 2 4