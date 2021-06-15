// To find path from src to other vertices having min. sum of weights.
// Used for negative weights.
vector<int> BellmanFord(int V,int src,vector<vector<int>>edges){   // {src,dest,weight}
      vector<int> dist(V,INT_MAX); // initialize to INT_MAX
    dist[src]=0;                                                  //dist from src will be zero
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
  for(int i=0; i < E; i++){
    int u=edges[i][0];
    int v=edges[i][1];
    int w=edges[i][2];
    if(dist[u] != INT_MAX && dist[u] + w <dist[v]){
      return {};                                            // there is a negative cycle
    }
  }
  return dist
}
