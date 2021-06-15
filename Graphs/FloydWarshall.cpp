// to find the min. distances between all vertices of a graph
void FloydWarshall(vector<vector<int>>graph, int V){
  vector<vector<int>dp(V,vector<int>(V,0));
  for(int i=0;i < V; i++){
    for(int j=0;j < V; j++){
      dp[i][j]=graph[i][j]
    }
  }
  for(int k=0; k < V; k++){
    for(int i=0; i < V; i++){
      for(int j=0; j < V; j++){
        if(dp[i][k] != INT_MAX && dp[k][j] != INT_MAX && dp[i][k] + dp[k][j] < dp[i][j]){
          dp[i][j] = dp[i][k] + dp[k][j];
        }
      }
    }
  }
}
