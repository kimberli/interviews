/*You are given a set of coins S. In how many ways can you make sum N assuming you have infinite amount of each coin in the set.

Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).*/

int Solution::coinchange2(vector<int> &A, int B) {
    int n=A.size();
    vector<long long int>dp(B+1,0);
    dp[0]=1;
    sort(A.begin(),A.end());
    for(int i=0;i<n;i++)
    {
        for(int j=A[i];j<=B;j++)
        {
            dp[j]=(dp[j]% 1000007+dp[j-A[i]]% 1000007)% 1000007;
        }
    }
    return dp[B]% 1000007;
}
