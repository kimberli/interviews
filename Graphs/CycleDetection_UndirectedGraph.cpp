void Cycle(int u,vector<int>arr[],vector<bool>visited,int p){
  visited[u] = true;
  
  for(auto &x:arr[u]){
    
    if(!visited[x] && Cycle(x,arr,visited,u))
      return true;
    
    else if(x != p)   // to check for back edge.
       return true;
  }
}

// call - Cycle(0, arr, visited, -1);
