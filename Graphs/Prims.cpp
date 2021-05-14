// to find the MST of the graph.
void Prims(int V,vector<int>arr[]){  // arr[u] is {v,weight}
  vector<bool>inMST(V,false);
  vector<int>key(V,INT_MAX);
  vector<int>parent(V,-1);
  int src=0;
  priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
  pq.push({0,src});
  key[src]=0;
  while(!pq.empty()){
    auto p = pq.top();
    pq.pop();
    int u = p.second;
    inMST[u] = true;
    for(auto &x:arr[u]){
      int v = x.first;
      int w  = x.second
      if(!inMST[v] && key[v] > w){
        key[v] = w;
        pq.push({key[v],v});
        parent[v] = u;
      }
    }
  }
  for(int i=1; i < V; i++){
    cout<< parent[i] << " " << i <<"\n";
  }
  // key[] contains the weight attached with each vertex. to get the sum of weights of MST, just add all elements in key
}
