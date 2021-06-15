int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m=A.size();
    int n=A[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));
    bool flag=false;
    for(int i=0;i<m;i++)
    {
        if(A[i][0]==0 && !flag)dp[i][0]=1;
        else
        {
            flag=true;
        }
    }
    flag=false;
    for(int j=0;j<n;j++)
    {
        if(A[0][j]==0 && !flag) dp[0][j]=1;
        else
        {
            flag=true;
        }
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(A[i][j]==0)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}
