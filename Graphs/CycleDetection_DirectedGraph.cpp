void Cycle(int u,vector<bool>&visited,vector<int>arr[],vector<bool>&visited){
  if(!visited[u]){
    recstack[u] = true;
    visited[u] = true;
    for(auto &x:arr[u]){
      if(!visited[x] && Cycle(x,visited,arr,recstack)){
        return true;
      }
      else if(recstack[x]) 
        return true;
    }
  }
  recstack[u] = false;
  return false;
}
