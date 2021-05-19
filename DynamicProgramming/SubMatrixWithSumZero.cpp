/*Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements inside the sub matrix is equal to 0. (note: elements might be negative).*/

int find(vector<int>&A)
{
    int ans=0;
    map<int,int>m;
    m[0]=1;
    int sum=0;
    for(int i=0;i<A.size();i++)
    {
        sum+=A[i];
        if(m.find(sum)!=m.end())
        {
            ans+=m[sum];
        }
        m[sum]++;
    }
    return ans;
}
int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    if(n==0) return 0;
    int m=A[0].size();
    int count=0;
    for(int left=0;left<m;left++)
    {
        vector<int>temp(n,0);
        for(int right=left;right<m;right++)
        {
            for(int i=0;i<n;i++)
            {
                temp[i]+=A[i][right];
            }
            int ans=find(temp);
            count+=ans;
        }
    }
    return count;
}
