int Solution::minimumTotal(vector<vector<int> > &triangle) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
         int n=triangle.size();
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
}
