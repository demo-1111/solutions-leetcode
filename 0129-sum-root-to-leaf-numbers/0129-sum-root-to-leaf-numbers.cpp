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
void path(TreeNode *root, int &val, int &res)
{
    if(root==NULL) return;
    val = val*10 +root->val;
    if(root->left==NULL && root->right==NULL)
        res+=val;
    path(root->left, val, res);
    path(root->right, val, res);
    val/=10;
}
int sumNumbers(TreeNode* root)
{
    int res=0, val=0;
    path(root, val, res);
    return res;
}
};