/*
Given a 2D binary matrix A of size  N x M  find the area of maximum size square sub-matrix with all 1's.
*/
int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int ans=0;
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int  i=0;i<n;i++) 
    {
        dp[i][0]=A[i][0];
        ans=max(ans,dp[i][0]);
    }
    for(int j=0;j<m;j++) 
    {
        dp[0][j]=A[0][j];
        ans=max(ans,dp[0][j]);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(A[i][j]==1)
                dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            ans=max(ans,dp[i][j]);
        }
    }
    return ans*ans;
}
