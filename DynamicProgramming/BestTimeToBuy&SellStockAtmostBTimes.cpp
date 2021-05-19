/*Given an array of integers A of size N in which ith element is the price of the stock on day i.

You can complete atmost B transactions.

Find the maximum profit you can achieve.

NOTE: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).*/
int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    B=min(B,n/2);
    vector<vector<int>>dp(n,vector<int>(B+1,0));
    for(int j=1;j<=B;j++)
    {
        int prev=INT_MIN;
        for(int i=1;i<n;i++)
        {
            prev=max(prev,dp[i-1][j-1]-A[i-1]);
            dp[i][j]=max(dp[i-1][j],prev+A[i]);
        }
    }
    return dp[n-1][B];
}
