/*You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the stables in such a way that the following conditions are satisfied:

You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. You have to preserve the ordering of the horses.
No stable should be empty and no horse should be left unaccommodated.
Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements*/

int solve(int i,int k,int n,string A, vector<vector<int>>&t)
{
    if(i>=n && k>0) return INT_MAX/2;
    if(t[i][k]!=-1) return t[i][k];
    int w=0,b=0;
    if(k==1)
    {
      for(int j=i;j<n;j++)
      {
          if(A[j]=='W') w++;
          else b++;
      }
      return t[i][k]= b*w;
    }
    int ans=INT_MAX/2;
    for(int j=i;j<n;j++)
    {
        if(A[j]=='W') w++;
        else b++;
        int temp=w*b+ solve(j+1,k-1,n,A,t);
        ans=min(temp,ans);
    }
    return t[i][k]=ans;
}
int Solution::arrange(string A, int B) {
    if(B>A.size()) return -1;
    vector<vector<int>>t(A.size()+1,vector<int>(B+1,-1));
    return solve(0,B,A.size(),A,t);
}
