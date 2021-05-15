// vertex from which we can access all other vertices.
void MotherVertex(){
  int v;
  vector<int>arr[V]; // the graph 
  vector<int>visited(V,false);
  for(int i = 0; i < V; i++){
    dfs(i,visited,arr);
    v = i;                    // candidate vertex
  }
  vector<int>visited1(V,false);
  dfs(v,visited1,arr);        // dfs on candidate vertex
  for(int i = 0; i < V;i++){
    if(!visited[i]) return -1;    // check if there is any unvisited vertex.
  }
  return v;
}

void dfs(int u, vector<bool>&visited,vector<int>arr[]){
  visited[u] = true;
  for(auto &x : arr[u]){
    if(!visited[x]){
      dfs(x,visited,arr);
    }
  }
}
