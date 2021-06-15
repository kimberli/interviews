// Find edges which when removed disconnects the graph
// ans contains the edges
// low -> lowest point reached using dfs from that point
// disc -> time of discovery of that point
void Bridges(){
    time++;
    low[u] = time;
    disc[u] = time;
  for(auto &v:arr[u]){
    if(!visited[v]){
      parent[v] = u;
      Bridges()
        low[u] = min(low[u], low[v]);
      if(low[v] > disc[u]){
        ans.push_back({u,v});
      }
    }
    else if (v != parent[u] ){
      low[u] = min(low[u], disc[v]);
    }
  }
  return ans;
}
