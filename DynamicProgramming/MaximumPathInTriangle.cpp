/*Given a 2D integer array A of size  N * N  representing a triangle of numbers.

Find the maximum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

NOTE:

Adjacent cells to cell (i,j) are only (i+1,j) and (i+1,j+1)
Row i contains i integer and n-i zeroes for all i in [1,n] where zeroes represents empty cells.*/
int Solution::solve(vector<vector<int> > &A) {
    int n=A.size()-1;
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<A[i+1].size();j++)
        {
            A[i][j]+=max(A[i+1][j],A[i+1][j+1]);
        }
    }
    return A[0][0];
}
