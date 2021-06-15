/*
Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,

i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

NOTE: Sub-sequence length should be greater than or equal to 2
*/
int Solution::anytwo(string A) {
    vector<vector<int>>dp(A.size()+1,vector<int>(A.size()+1,0));
    int res=-1;
    for(int i=0;i<=A.size();i++)
    {
        for(int j=0;j<=A.size();j++)
        {
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=A.size();i++)
    {
        for(int j=1;j<=A.size();j++)
        {
            if(A[i-1]==A[j-1] && i!=j)
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    if(dp[A.size()][A.size()]>=2) return 1;
    return 0;
}
