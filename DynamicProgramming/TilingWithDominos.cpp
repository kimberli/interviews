/*Problem Description

Given an integer A you have to find the number of ways to fill a 3 x A board with 2 x 1 dominoes.

Return the answer modulo 109 + 7 .

*/
int Solution::solve(int A) 
{
    if(A%2) return 0;
    vector<long long int> a(A+1, 0), c(A+1,0);
    a[1]=1, c[1]=0, a[2]=0, c[2]=3;
    
    for(int i=3;i<=A;i++)
    {
        c[i]=(2*a[i-1]+c[i-2])%1000000007;
        a[i]=(c[i-1]+a[i-2])%1000000007;
    }
    return c[A];
}
