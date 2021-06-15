int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    vector<vector<bool>>dp(n+1,vector<bool>(B+1,false));
    for(int i=1;i<=B;i++)
    {
        dp[0][i]=false;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=B;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=A[i-1])
            {
                dp[i][j]=dp[i][j]||dp[i-1][j-A[i-1]];
            }
        }
    }
    return dp[n][B];
}
