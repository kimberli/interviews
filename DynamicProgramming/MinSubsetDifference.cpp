int Solution::solve(vector<int> &A) {
    int n=A.size();
    if(n==1) return A[0];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
    }
    vector<vector<bool>>dp(n+1,vector<bool>(sum/2+1,false));
    for(int i=1;i<=n;i++) dp[i][0]=true;
    for(int i=1;i<=sum/2;i++) dp[0][i]=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum/2;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=A[i-1])
            {
                dp[i][j]=dp[i][j]||dp[i-1][j-A[i-1]];
            }
        }
    }
    int minval=INT_MAX;
    for(int i=1;i<=sum/2;i++)
    {
        if(dp[n][i])
        {
            minval=min(minval,abs(sum-2*i));
        }
    }
    return minval;
}
