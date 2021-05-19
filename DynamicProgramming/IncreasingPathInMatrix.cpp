/*Given a 2D integer matrix A of size N x M.

From A[i][j] you can move to A[i+1][j], if A[i+1][j] > A[i][j], or can move to A[i][j+1] if A[i][j+1] > A[i][j].

The task is to find and output the longest path length if we start from (0, 0).

NOTE:

If there doesn't exist a path return -1.*/
int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    int ans=-1;
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) continue;
            if(i==0 || j==0)
            {
                if(i==0)
                {
                    if(A[i][j]>A[i][j-1] && dp[i][j-1]!=0)
                        dp[i][j]=1+dp[i][j-1];
                }
                else
                {
                    if(A[i][j]>A[i-1][j] && dp[i-1][j]!=0)
                        dp[i][j]=1+dp[i-1][j];
                }
            }
            else
            {
                if(A[i][j]>A[i-1][j] && dp[i-1][j]!=0)
                    dp[i][j]=max(dp[i][j],1+dp[i-1][j]);
                if(A[i][j]>A[i][j-1] && dp[i][j-1]!=0)
                {
                    dp[i][j]=max(dp[i][j],1+dp[i][j-1]);
                }
            }
        }
    }
    if(dp[n-1][m-1]==0) return -1;
    return dp[n-1][m-1];
}
