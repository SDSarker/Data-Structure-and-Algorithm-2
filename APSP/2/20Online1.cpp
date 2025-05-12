#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &dist,vector<vector<int>> &parent,int n) {
    // Code here
    
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
        dist[v][u]=w;
        parent[u][v]=u;
        parent[v][u]=v;
    }

    int w1,w2;
    cin>>w1>>w2;
    int s,d;
    cin>>s>>d;

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(parent[i][j]==0) cout<<"Nil"<<" ";
    //         else cout<<parent[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    floydWarshall(dist,parent,n);

    // cout<<"Shortest distance matrix:"<<endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(dist[i][j]==1e8) cout<<"Inf"<<" ";
    //         else cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(parent[i][j]==0) cout<<"Nil"<<" ";
    //         else cout<<parent[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    if((dist[s][w1]+dist[w1][w2]+dist[w2][d])>=1e8 && (dist[s][w2]+dist[w2][w1]+dist[w1][d])>=1e8){
        cout<<"No path from "<<s<<"to "<< d<<" through the Wall Street"<<endl;
    }
    else if((dist[s][w1]+dist[w1][w2]+dist[w2][d])<(dist[s][w2]+dist[w2][w1]+dist[w1][d])){
        cout<<"Shortest path weight : "<<(dist[s][w1]+dist[w1][w2]+dist[w2][d])<<endl;
        stack<int> path;
        path.push(w1);
        int cur=w1;
        while(cur!=s){
            path.push(parent[s][cur]);
            cur=parent[s][cur];
        }
        cout<<"Path :";
        while(!path.empty()){
            cout<<path.top()<<" -> ";
            path.pop();
        }
        path.push(d);
        cur=d;
        while(cur!=w2){
            path.push(parent[w2][cur]);
            cur=parent[w2][cur];
        }

        while(!path.empty()){
            cout<<path.top()<<" -> ";
            path.pop();
        }

    }
    else{
        cout<<"Shortest path weight : "<<(dist[s][w2]+dist[w2][w1]+dist[w1][d])<<endl;
        stack<int> path;
        path.push(w2);
        int cur=w2;
        while(cur!=s){
            path.push(parent[s][cur]);
            cur=parent[s][cur];
        }
        cout<<"Path :";
        while(!path.empty()){
            cout<<path.top()<<" -> ";
            path.pop();
        }
        path.push(d);
        cur=d;
        while(cur!=w1){
            path.push(parent[w1][cur]);
            cur=parent[w1][cur];
        }

        while(!path.empty()){
            cout<<path.top()<<" -> ";
            path.pop();
        }
    }
}


// 8 8
// 1 6 5
// 2 5 8
// 2 6 7
// 4 6 8
// 5 4 2
// 5 7 7
// 7 6 7
// 8 4 8
// 2 6
// 5 3