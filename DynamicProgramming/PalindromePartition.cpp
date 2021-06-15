/*Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.*/
int Solution::minCut(string s) {
           int n=s.size();
        vector<int>c(n,INT_MAX);
        vector<vector<bool>>p(n,vector<bool>(n,0));
        for(int i=0;i<n;i++)
        {
            p[i][i]=true;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                p[i][i+1]=true;
            }
        }
        for(int len=3;len<=n;len++)
        {
            for(int i=0;i<n-len+1;i++)
            {
                int j=i+len-1;
                if(s[i]==s[j] && p[i+1][j-1])
                {
                    p[i][j]=true;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(p[0][i]) 
            {
                c[i]=0;
                continue;
            }
            for(int j=0;j<i;j++)
            {
                if(p[j+1][i])
                {
                    c[i]=min(c[i],c[j]+1);
                }
            }
        }
        return c[n-1];
}
