/*
Problem Description

There are a row of N houses, each house can be painted with one of the three colors: red, blue or green.

The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a N x 3 cost matrix A.

For example, A[0][0] is the cost of painting house 0 with color red; A[1][2] is the cost of painting house 1 with color green, and so on.

Find the minimum total cost to paint all houses.
*/
int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<3;j++)
        {
            A[i][j]+=min(A[i+1][(j+1)%3],A[i+1][(j+2)%3]);
        }
    }
    return min(A[0][0],min(A[0][1],A[0][2]));
}
