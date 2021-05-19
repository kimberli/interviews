/*
Given a string A and a dictionary of words B, determine if A can be segmented into a space-separated sequence of one or more dictionary words.
*/
int Solution::wordBreak(string A, vector<string> &B) {
    int n=A.size();
    vector<bool>dp(A.size()+1,false);
    dp[n]=true;
    map<string,int>m;
    for(int i=0;i<B.size();i++)
    {
        m[B[i]]++;
    }
    for(int i=n-1;i>=0;i--)
    {
        string temp;
        for(int j=i;j<n;j++)
        {
            temp.push_back(A[j]);
            if(m.find(temp)!=m.end())
            {
                if(dp[j+1])
                {
                    dp[i]=true;
                    break;
                }
            }
        }
    }
    return dp[0];
}
