// to check if graph is bipartite
// also, check for self loops. graphs will not be bipartite in that case
// this algo uses bfs to check for bipartition
// A bipartite graph can never have a cycle of odd length.
bool Bipartite(){
  queue<int>q;
  vector<int>color(V,-1);
  for(int i = 0; i < V; i++){
    if(color[i] == -1){
      color[i] = 0;
      q.push(i);
      while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto &x:arr[u]){
          if(color[x] == -1){
            color[x] = 1-color[u];
            q.push(x);
          }
          else if (color[x] == color[u]) 
            return false;
        }
      }
    }
  }
  return true;
}
