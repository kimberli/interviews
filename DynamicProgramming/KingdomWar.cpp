/*Two kingdoms are on a war right now, kingdom X and kingdom Y. As a war specialist of kingdom X, you scouted kingdom Y area.

A kingdom area is defined as a N x M grid with each cell denoting a village.
Each cell has a value which denotes the strength of each corresponding village.
The strength can also be negative, representing those warriors of your kingdom who were held hostages.

There’s also another thing to be noticed.

The strength of any village on row larger than one (2<=r<=N) is stronger or equal to the strength of village which is exactly above it.
The strength of any village on column larger than one (2<=c<=M) is stronger or equal to the strength of vilage which is exactly to its left.
(stronger means having higher value as defined above).
So your task is, find the largest sum of strength that you can erase by bombing one sub-matrix in the grid.*/

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    for(int i=0;i<n;i++){
        int sum=A[i][m-1];
        for(int j=m-2;j>=0;j--){
            A[i][j]+=sum;
            sum=A[i][j];
        }
    }
    int ans=A[n-1][m-1];
    for(int i=0;i<m;i++){
        int sum=A[n-1][i];
        int mx=sum;
        for(int j=n-2;j>=0;j--){
            A[j][i]+=sum;
            sum=A[j][i];
            mx=max(mx,sum);
        }
        ans=max(ans,mx);
    }
    return ans;
}
