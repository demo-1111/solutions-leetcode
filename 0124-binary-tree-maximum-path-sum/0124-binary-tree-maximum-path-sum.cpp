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
int RecMaxPathSum(TreeNode *root, int &res)
{
    if(root==NULL)
        return 0;
    int l=max(0,RecMaxPathSum(root->left, res));
    int r=max(0,RecMaxPathSum(root->right, res));
    res=max(res, root->val+l+r);
    return root->val+max(l,r);
}
int maxPathSum(TreeNode* root)
{
    int res=INT_MIN;
    RecMaxPathSum(root, res);
    return res;
}

};