/*Given an array of non-negative integers, A, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.*/

int Solution::canJump(vector<int> &A) {
    int maxindex=0;
    if(A.size()==1) return 1;
    for(int i=0;i<A.size();i++)
    {
        maxindex=max(maxindex,i+A[i]);
        if(i>=maxindex) return 0;
        if(maxindex >= A.size()-1) return 1;
    }
    return 0;
}
