#include <bits/stdc++.h>
using namespace std;
vector<int> BellmanFord(vector<vector<int>> edges,int n){
    //Extra edge add korbo
    vector<vector<int>> extraEdge;
    for(auto i:edges){
        extraEdge.push_back({i[0],i[1],i[2]});
    }
    for(int i=0;i<n;i++){
        extraEdge.push_back({n,i,0});
    }

    //bellman
    vector<int> dist(n+1,1e9);
    dist[n]=0;
    for(int k=0;k<n;k++){
        for(auto i:extraEdge){
            if(dist[i[0]]!=1e9 && dist[i[1]]>dist[i[0]]+i[2]){
                dist[i[1]]=dist[i[0]]+i[2];
            }
        }
    }

    return dist;
}

void JohnsonAlgorithm(vector<vector<int>> graph){
    int n=graph.size();
    vector<vector<int>> edges;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]!=0){
                edges.push_back({i,j,graph[i][j]});
            }
        }
    }

    vector<int> adjustedDist=BellmanFord(edges,n);

    //notun matrix banabo
    vector<vector<int>> adjustedGraph(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]!=0){
                adjustedGraph[i][j]=graph[i][j]+adjustedDist[i]-adjustedDist[j];
            }
        }
    }

    //Notun graph print kori
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adjustedGraph[i][j]<<" ";
        }
        cout<<endl;
    }

    //dijkstra er jonno adj list banai
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]!=0){
                adj[i].push_back({j,adjustedGraph[i][j]});
            }
        }
    }

    //notun graph er basis e each node dhore dijkstra mari
    for(int src=0;src<n;src++){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
        Q.push({0,src});
        vector<int> dist(n+1,1e9);
        dist[src]=0;
        while(!Q.empty()){
            int weight=Q.top().first;
            int node=Q.top().second;
            Q.pop();
            for(auto i:adj[node]){
                int v=i.first;
                int w=i.second;
                if(w+weight<dist[v]){
                    dist[v]=w+weight;
                    Q.push({w+weight,v});
                }
            }
        }

        cout<<"Shortest Distance from "<<src<<":"<<endl;
        for(int i=0;i<n;i++){
            cout<<"    To "<<i<<" : "<<dist[i]<<endl;
        }
        cout<<endl;
    }
}


int main()
{
    // Define a graph with possible negative weights
    vector<vector<int>> graph = {
        {0, -5, 2, 3},
        {0, 0, 4, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};

    // Execute Johnson's Algorithm
    JohnsonAlgorithm(graph);
    return 0;
}



// #include <iostream>
// #include <vector>
// #include <limits>
// #include <algorithm>

// #define INF std::numeric_limits<int>::max()

// using namespace std;

// // Function to find the vertex with the minimum distance
// // that has not yet been included in the shortest path tree
// int Min_Distance(const vector<int>& dist, const vector<bool>& visited) {
//     int min = INF, min_index;
//     for (int v = 0; v < dist.size(); ++v) {
//         if (!visited[v] && dist[v] <= min) {
//             min = dist[v];
//             min_index = v;
//         }
//     }
//     return min_index;
// }

// // Function to perform Dijkstra's algorithm on the modified graph
// void Dijkstra_Algorithm(const vector<vector<int>>& graph, const vector<vector<int>>& altered_graph, int source) {
//     int V = graph.size();  // Number of vertices
//     vector<int> dist(V, INF);  // Distance from source to each vertex
//     vector<bool> visited(V, false);  // Track visited vertices
    
//     dist[source] = 0;  // Distance to source itself is 0

//     // Compute shortest path for all vertices
//     for (int count = 0; count < V - 1; ++count) {
//         // Select the vertex with the minimum distance that hasn't been visited
//         int u = Min_Distance(dist, visited);
//         visited[u] = true;  // Mark this vertex as visited

//         // Update the distance value of the adjacent vertices of the selected vertex
//         for (int v = 0; v < V; ++v) {
//             if (!visited[v] && graph[u][v] != 0 && dist[u] != INF && dist[u] + altered_graph[u][v] < dist[v]) {
//                 dist[v] = dist[u] + altered_graph[u][v];
//             }
//         }
//     }

//     // Print the shortest distances from the source
//     cout << "Shortest Distance from vertex " << source << ":\n";
//     for (int i = 0; i < V; ++i) {
//         cout << "Vertex " << i << ": " << (dist[i] == INF ? "INF" : to_string(dist[i])) << endl;
//     }
// }

// // Function to perform Bellman-Ford algorithm to find shortest distances
// // from a source vertex to all other vertices
// vector<int> BellmanFord_Algorithm(const vector<vector<int>>& edges, int V) {
//     vector<int> dist(V + 1, INF);  // Distance from source to each vertex
//     dist[V] = 0;  // Distance to the new source vertex (added vertex) is 0

//     // Add a new source vertex to the graph and connect it to all original vertices with 0 weight edges
//     vector<vector<int>> edges_with_extra(edges);
//     for (int i = 0; i < V; ++i) {
//         edges_with_extra.push_back({V, i, 0});
//     }

//     // Relax all edges |V| - 1 times
//     for (int i = 0; i < V; ++i) {
//         for (const auto& edge : edges_with_extra) {
//             if (dist[edge[0]] != INF && dist[edge[0]] + edge[2] < dist[edge[1]]) {
//                 dist[edge[1]] = dist[edge[0]] + edge[2];
//             }
//         }
//     }
//     return vector<int>(dist.begin(), dist.begin() + V);  // Return distances excluding the new source vertex
// }

// // Function to implement Johnson's Algorithm
// void JohnsonAlgorithm(const vector<vector<int>>& graph) {
//     int V = graph.size();  // Number of vertices
//     vector<vector<int>> edges;
    
//     // Collect all edges from the graph
//     for (int i = 0; i < V; ++i) {
//         for (int j = 0; j < V; ++j) {
//             if (graph[i][j] != 0) {
//                 edges.push_back({i, j, graph[i][j]});
//             }
//         }
//     }

//     // Get the modified weights from Bellman-Ford algorithm
//     vector<int> altered_weights = BellmanFord_Algorithm(edges, V);
//     vector<vector<int>> altered_graph(V, vector<int>(V, 0));

//     // Modify the weights of the edges to remove negative weights
//     for (int i = 0; i < V; ++i) {
//         for (int j = 0; j < V; ++j) {
//             if (graph[i][j] != 0) {
//                 altered_graph[i][j] = graph[i][j] + altered_weights[i] - altered_weights[j];
//             }
//         }
//     }

//     // Print the modified graph with re-weighted edges
//     cout << "Modified Graph:\n";
//     for (const auto& row : altered_graph) {
//         for (int weight : row) {
//             cout << weight << ' ';
//         }
//         cout << endl;
//     }

//     // Run Dijkstra's algorithm for every vertex as the source
//     for (int source = 0; source < V; ++source) {
//         cout << "\nShortest Distance with vertex " << source << " as the source:\n";
//         Dijkstra_Algorithm(graph, altered_graph, source);
//     }
// }

// // Main function to test the Johnson's Algorithm implementation
// int main() {
//     // Define a graph with possible negative weights
//     vector<vector<int>> graph = {
//         {0, -5, 2, 3},
//         {0, 0, 4, 0},
//         {0, 0, 0, 1},
//         {0, 0, 0, 0}
//     };

//     // Execute Johnson's Algorithm
//     JohnsonAlgorithm(graph);
//     return 0;
// }