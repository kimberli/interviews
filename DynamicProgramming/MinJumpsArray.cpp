/*Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Return the minimum number of jumps required to reach the last index.

If it is not possible to reach the last index, return -1.*/
int Solution::jump(vector<int> &A) {
    int n=A.size();
    int furthest=0;
    int end=0;
    int jumps=0;
    if(n==1||n==0)return 0;
    if(A[0]==0) return -1;
    for(int i=0;i<n-1;i++)
    {
        furthest=max(furthest,i+A[i]);
        if(i==end)
        {
            jumps++;
            end=furthest;
        }
    }
    if(furthest<n-1)
        return -1;
    return jumps;
}
