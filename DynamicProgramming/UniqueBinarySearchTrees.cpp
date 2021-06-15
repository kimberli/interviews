/*Given an integer A, how many structurally unique BST’s (binary search trees) exist that can store values */
// Catalan Number uses.
/*
1. Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
2. Count the number of possible Binary Search Trees with n keys (See this)
3. Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
4. Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.
*/
int Solution::numTrees(int A) {
    int n=A;
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=A;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}
