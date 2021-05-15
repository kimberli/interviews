// Method 1
// simply attach the subset of px to py. 
int find(vector<int>&parent, int x){
  if(parent[x] == -1){
    return x;
  }
  return parent[x] = find(parent,parent[x]);
}
void  Union(int x, int y){
  int px = find(parent,x);
  int py = find(parent,y);
  parent[px] = py;
}
// If you want to check for cycle
int checkcycle(){
  for(int i = 0; i<edges.size(); i++){
    int x = edges[i][0];
    int y = edges[i][1];
    if(find(parent,x) == find(parent,y))
      return 1;
    Union(x,y);
  }
  return 0;
}

//Method 2
// attaching smaller subset to larger subset
// This is computationally better
// parent vector holds parent
// size holds the size
int find(vector<int>&parent,int x){
  if(parent[x] == -1){
    return x;
  }
  return parent[x] = find(parent,parent[x]);
}
int Union(){
  if(size[x] < size[y]){
    parent[x] = y;
  }
  else if(size[x] > size[y]){
    parent[y] = x;
  }
  else{
    parent[y] = x;
    size[x] += size[y];
  }
}
void formDSU(){
  for(int i = 0;i < edges.size();i++){
    int x = edges[i][0];
    int y = edges[i][1];
    if(find(parent,x) != find(parent,y))
      Union(x,y);
  }
}


























