/*Given an integer array A of size N. You have to merge all the elements of the array into one with the minimum possible cost.

The rule for merging is as follows:

Choose any two adjacent elements of the array with values say X and Y and merge them into a single element with value (X + Y) paying a total cost of (X + Y).
Return the minimum possible cost of merging all elements.*/
int Solution::solve(vector<int> &A) {
    int  n=A.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    vector<int>prefix_sum(n,0);
    prefix_sum[0]=A[0];
    for(int i=1;i<n;i++)
    {
        prefix_sum[i]=prefix_sum[i-1]+A[i];
    }
    for(int len=1;len<n;len++)
    {
        for(int i=0;i<n-len;i++)
        {
            int j=i+len;
            int res=INT_MAX;
            for(int k=i;k<j;k++)
            { 
                res=min(res,dp[i][k]+dp[k+1][j]);
            }
            dp[i][j] = (prefix_sum[j]-((i==0)? 0 : prefix_sum[i-1])) + res;
        }
    }
    return dp[0][n-1];
}
