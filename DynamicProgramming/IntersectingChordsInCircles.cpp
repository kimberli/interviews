int Solution::chordCnt(int A) 
{
long long int m = 1000000007;
long long int dp[A+1];
dp[0] = 1;
dp[1]=1;
for(long long int i=2;i<=A;i++)
{
    dp[i] = 0;
    for(long long int j=0;j<i;j++)
    {
        long long int temp = (dp[j]%m * dp[i-j-1]%m)%m;
        dp[i] = (dp[i]%m+temp%m)%m;
    }
}
return (dp[A]+m)%m;
}
