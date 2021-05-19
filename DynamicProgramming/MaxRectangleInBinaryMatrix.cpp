/*Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.*/
int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    vector<int>heights(m,0);
    vector<int>left(m,0);
    vector<int>right(m,m-1);
    int ans=0;
    for(int i=0;i<n;i++)
    {
            int curr_left=0;
        int curr_right=m-1;
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==1)
            {
                heights[j]++;
            }
            else heights[j]=0;
        }
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==1)
            {
                left[j]=max(left[j],curr_left);
            }
            else 
            {
                left[j]=0;
                curr_left=j+1;
            }
        }
        for(int j=m-1;j>=0;j--)
        {
            if(A[i][j]==1)
            {
                right[j]=min(right[j],curr_right);
            }
            else
            {
                right[j]=m;
                curr_right=j-1;
            }
        }
        for(int j=0;j<m;j++)
        {
            ans=max(ans,(right[j]-left[j]+1)*heights[j]);
        }
    }
    return ans;
}
