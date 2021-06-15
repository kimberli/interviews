/*Find the contiguous subarray within an array (containing at least one number) which has the largest product.
Return an integer corresponding to the maximum product possible.*/
int Solution::maxProduct(const vector<int> &A) {
    int minforward=INT_MIN;
    int maxbackward=INT_MIN;
    int prod=1;
    bool iszero=false;
    for(int i=0;i<A.size();i++)
    {
        prod*=A[i];
        if(prod==0)
        {
            iszero=true;
            prod=1;
            continue;
        }
        minforward=max(minforward,prod);
    }
    prod=1;
    for(int i=A.size()-1;i>=0;i--)
    {
        prod*=A[i];
        if(prod==0)
        {
            iszero=true;
            prod=1;
            continue;
        }
        maxbackward=max(maxbackward,prod);
    }
    if(iszero) return max(0,max(minforward,maxbackward));
    return max(maxbackward,minforward);
}
