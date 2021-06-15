/*
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/
int Solution::minDistance(string A, string B) {
    int n=A.size();
    int m=B.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                if(i==0) dp[i][j]=j;              // need to delete all char of one string to make it equal to 0
                else dp[i][j]=i;                   // need to insert...
            }
            else if(A[i-1]==B[j-1])
            {
                dp[i][j]=dp[i-1][j-1];            // same char. no need of operation
            }
            else
            {
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));                 
            }
        }
    }
    return dp[n][m];
}
