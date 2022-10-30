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
    
bool fun(TreeNode *root, long long mn, long long mx)
{
    if(root==NULL)
        return true;
    if(root->val>mn && root->val<mx)
        return fun(root->left, mn, root->val) && 
                fun(root->right, root->val, mx);
    else return false;
}
bool isValidBST(TreeNode* root)
{
    return fun(root, INT64_MIN, INT64_MAX);
}
    
};