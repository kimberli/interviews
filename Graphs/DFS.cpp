// dfs algorithm
// arr[u] is of the form {v, weight}
// V -> vertices
void dfs(int u,vector<bool>&visited, vector<int>arr[]){
  visited[u] = true;                 
  for(auto &x:arr[u]){
    if(!visited[x.first]){
      dfs(x.first,visited,arr);
    }
  }
}

int main(){
  // to cover entire graph in case it is disconnected.
  for(int i=0;i<V;i++){
    if(!visited[i])
        dfs(i,visited,arr);
  }
}
