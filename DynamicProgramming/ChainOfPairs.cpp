/*Given a N * 2 array A where (A[i][0], A[i][1]) represents the ith pair.

In every pair, the first number is always smaller than the second number.

A pair (c, d) can follow another pair (a, b) if b < c , similarly in this way a chain of pairs can be formed.

Find the length of the longest chain subsequence which can be formed from a given set of pairs.*/


int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    vector<int>dp(n,1);
    int ans=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[i][0]>A[j][1])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
            ans=max(ans,dp[i]);
        }
    }
    return ans;
}
