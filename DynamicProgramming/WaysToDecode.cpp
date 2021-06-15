/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
Given an encoded message A containing digits, determine the total number of ways to decode it modulo 109 + 7.
*/

int Solution::numDecodings(string s) {
    int n=s.size();
    vector<long long int>count(n+1,0);
    if(n==0) return 0;
    if(s[0]=='0') return 0;
    count[0]=1;
    count[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i-1]>'0')
        {
            count[i]=count[i-1];
        }
        if(s[i-2]=='1' || s[i-2]=='2' && s[i-1]<'7')
        {
            count[i]=(count[i]%1000000007+count[i-2]%1000000007)%1000000007;
        }
    }
    return count[n]%1000000007;
}
