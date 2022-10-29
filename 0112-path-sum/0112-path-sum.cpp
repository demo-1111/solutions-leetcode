/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool RechasPathSum(TreeNode* root, int targetSum)
{
    if(root==NULL) return false;
    int cur=targetSum-root->val;
    if(root->left==NULL && root->right==NULL && cur==0)
        return true;
    return RechasPathSum(root->left, cur) || 
            RechasPathSum(root->right, cur);
}
bool hasPathSum(TreeNode* root, int targetSum)
{
    return RechasPathSum(root,targetSum);
}
};