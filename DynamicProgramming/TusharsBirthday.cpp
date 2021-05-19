/*
As it is Tushar’s Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune.
Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar’s friends are satisfied (reached their eating capacity).

NOTE:

Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish unlimited number of times.
There always exists a dish with filling capacity 1 so that a solution always exists.
*/
int Solution::solve(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
int maxi = *max_element(a.begin(),a.end());
    vector<vector<long long> >dp(b.size()+1,vector<long long>(maxi+1,INT_MAX));
    for(int i=0;i<=b.size();i++){
     dp[i][0] = 0;
    }
  for(int i=1;i<=maxi;i++){
     if(i % b[0] == 0){
     dp[1][i] = (i/b[0])*c[0];
  }
}
 for(int i=2;i<=b.size();i++){
   for(int j=1;j<=maxi;j++){
    if(b[i-1] > j){
        dp[i][j] = dp[i-1][j];
    }
    else {
       dp[i][j] = min(dp[i-1][j],min((c[i-1]+dp[i-1][j-b[i-1]]),(c[i-1]+dp[i][j-b[i-1]])));
    }
  }
}
 int sum=0;
 for(int i=0;i<a.size();i++){
sum += dp[b.size()][a[i]];
 } 
 return sum;
 }
