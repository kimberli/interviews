/*
Given an array of positive elements, you have to flip the sign of some of its elements such that the resultant sum of the elements of array should be minimum non-negative(as close to zero as possible). Return the minimum no. of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.
*/
int Solution::solve(const vector<int> &A) {
int n = A.size();
int sumv = 0;
for(int i=0;i<n;i++){
    sumv += A[i];
}
int req = sumv/2;
vector<vector<int> > dp(n+1,vector<int>(req+1,INT_MAX));
dp[0][0] = 0;
for(int i=0;i<=n;i++)
{
    dp[i][0] = 0;
}
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=req;j++)
    {
        int a=INT_MAX;
        int b;
        if(j>=A[i-1])
        {
            a = dp[i-1][j-A[i-1]];
            if(a!=INT_MAX) a+=1;
        }
        b = dp[i-1][j];
        dp[i][j] = min(a,b);
    }
}
for(int i=req;i>=0;i--){
    if(dp[n][i]!=INT_MAX){
        return dp[n][i];
    }
}
}
