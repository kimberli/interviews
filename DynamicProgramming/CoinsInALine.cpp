/*There are A coins (Assume A is even) in a line.

Two players take turns to take a coin from one of the ends of the line until there are no more coins left.

The player with the larger amount of money wins, Assume that you go first.

Return the maximum amount of money you can win.*/
int ans(int start,int end,vector<int>&A,vector<vector<int>>&dp)
{
    if(start==end) return dp[start][end]=A[end];
    if(dp[start][end]!=-1) return dp[start][end];
    int res=max(A[start]-ans(start+1,end,A,dp), A[end]-ans(start,end-1,A,dp));
    return dp[start][end]=res;
}
int Solution::maxcoin(vector<int> &A) {
    int n=A.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    ans(0,A.size()-1,A,dp);
    int sum=0;
    for(int i=0;i<A.size();i++) sum+=A[i];
    
    return (dp[0][n-1]+sum)/2;
}
