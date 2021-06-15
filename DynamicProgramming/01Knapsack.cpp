/*
Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.

Also given an integer C which represents knapsack capacity.

Find out the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.

NOTE:
You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
*/
int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n=A.size();
    int m=B.size();
    vector<vector<int>>dp(n+1,vector<int>(C+1,0));
    for(int i=1;i<=n;i++)dp[i][0]=0;
    for(int i=1;i<=C;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=C;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=B[i-1])
            {
                dp[i][j]=max(dp[i][j], A[i-1] +dp[i-1][j-B[i-1]]);
            }
        }
    }
    return dp[n][C];
}
