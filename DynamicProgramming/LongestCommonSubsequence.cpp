void LCS(string a,string b){
  int n = a.size();
  int m = b.size();
  vector<vector<int>>dp(n+1,vector<int>(m+1,));
  for(int i = 0;i <= n;i++){
    for(int j = 0; j <= m;j++){
      if(i == 0 || j == 0){
        dp[i][j] = 0;
      }
      else if(a[i - 1] == b[j - 1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else 
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[n][m];
}
