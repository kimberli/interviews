// BFS algo
// arr[u] is of the form {v,weight}
void BFS(int src,vector<int>arr[]){
  queue<int>q;
  q.push(src);
  vector<bool>visited(V,false);
  visited[src] = true;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(auto &x:arr[u]){
      int v = x.first;
      if(!visited[v]){
        q.push(v);
      }
    }
  }
}
for(int i = 0; i < V; i++){
  if(!visited[i]){
    BFS(i,arr);
  }
}
