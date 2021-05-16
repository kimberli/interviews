//change weight to -w for shortest path 
//Method 1 - simple DFS O(V*(V+E))
void LongestPath(int u, int sum, vector<bool>&visited, vector<int>arr[], int &ans){
  visited[src] = true;
  int curr = 0;
  for(auto &x:arr[u]){
    int v = x.first;
    int w = x.second;
    if(!visited[v]){
     curr = sum + w;
     LongestPath(v, curr, visited, arr, ans);
    }
     ans=max(ans, curr);
  }
}
 
// Method 2- For a directed graph only O(V*(V+E))
// Gives longest path between src and any other vertex
void LongestPath(int src){
  // create topological sort/
  vector<int>dist(V,INT_MIN);
  dist[src] = 0;
  stack<int>s; // s is the stack after topological sort
  while(!s.empty()){
    int u = s.top();
    s.pop();
    for(auto &x:arr[u]){
      int v = x.first;
      int w = x.second;
      if(dist[v] < dist[u] + w){
        dist[v] = dist[u] + w;
      }
    }
  }
}
