int Solution::solve(string A) {
    vector<vector<int>>dp(A.size(),vector<int>(A.size(),0));
    int res=1;
    for(int i=0;i<A.size();i++)
    {
        dp[i][i]=1;
    }
    for(int len=2;len<=A.size();len++)
    {
        for(int i=0;i<A.size()-len+1;i++)
        {
            int j=i+len-1;
            if(A[i]==A[j]&&len==2)
            {
                dp[i][j]=2;
            }
            else if(A[i]==A[j])
            {
                dp[i][j]=dp[i+1][j-1]+2;
                res=max(res,len);
            }
            else
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }

        }
    }
    return dp[0][A.size()-1];
}
