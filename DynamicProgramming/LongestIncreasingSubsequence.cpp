int Solution::lis(const vector<int> &A) {
    int n=A.size();
    vector<int>d(n+1,INT_MAX);
    d[0]=INT_MIN;
    for(int i=0;i<n;i++)
    {
        auto j=upper_bound(d.begin(),d.end(),A[i])-d.begin();
        if(A[i]>d[j-1] && A[i]<d[j])
        {
            d[j]=A[i];
        }
    }
    int ans=-1;
    for(int i=0;i<=n;i++)
    {
        if(d[i]<INT_MAX) ans=i;
    }
    return ans;
}
