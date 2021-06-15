/*
Given a binary tree T, find the maximum path sum.
The path may start and end at any node in the tree.
*/





/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int help(TreeNode* A,int &ans){
     if(!A) return 0;
     int l=help(A->left,ans);
     int r=help(A->right,ans);
     int sum=max(max(l,r)+A->val,A->val);
     int max_top=max(sum,l+r+A->val);
     ans=max(ans,max_top);
     return sum;
 }
int Solution::maxPathSum(TreeNode* A) {
    int ans=INT_MIN;
    help(A,ans);
    return ans;
}
