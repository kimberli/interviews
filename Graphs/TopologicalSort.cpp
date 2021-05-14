// This yields the topological sort for the DAG arr[]
// vertex with indegree 0, 1, 2, and so on...
/*         *****Applications******
    1. Sorted dictionary of alien language. (popular question)
    2. Longest path problems for DAG.
    3. Add max edges so that no cycle is formed.
*/
void Topo(stack<int>&s,vector<bool>&visited,vector<int>arr[],int u){
  visited[u] = true;
  for(auto &x:arr[u]){
    if(!visited[x]){
      Topo(s,visited,arr,x);
    }
  }
  s.push(u);
}
