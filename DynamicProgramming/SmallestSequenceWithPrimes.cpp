/*
GIven three prime numbers A, B and C and an integer D.

You need to find the first(smallest) D integers which only have A, B, C or a combination of them as their prime factors.
*/
vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int>ans;
    int i1=0;
    int i2=0;
    int i3=0;
    int next_A=A;
    int next_B=B;
    int next_C=C;
    vector<int>dp(D);
    for(int i=0;i<D;i++)
    {
        int temp=min(next_A,min(next_B,next_C));
        dp[i]=temp;
        if(temp==next_A){
            next_A=A*dp[i1];
            i1++;
        }
        if(temp==next_B){
            next_B=B*dp[i2];
            i2++;
        }
        if(temp==next_C){
            next_C=C*dp[i3];
            i3++;
        }
    }
    return dp;
}
