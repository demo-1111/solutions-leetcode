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
// int RecMaxPathSum(TreeNode *root, int &res)
// {
//     if(root==NULL)
//         return 0;
//     int l=max(0,RecMaxPathSum(root->left, res));
//     int r=max(0,RecMaxPathSum(root->right, res));
//     res=max(res, root->val+l+r);
//     return root->val+max(l,r);
// }
// int maxPathSum(TreeNode* root)
// {
//     int res=INT_MIN;
//     RecMaxPathSum(root, res);
//     return res;
// }
    
    
int maxf(int a, int b, int c, int d)
{
    return max(a, max(b, max(c,d)));
}
int RecMaxPathSum(TreeNode *root, int &res)
{
    if(root==NULL)
        return 0;
    int l=RecMaxPathSum(root->left, res);
    int r=RecMaxPathSum(root->right, res);
    int cur=root->val+max(l,r);
    res=maxf(res,cur,root->val, root->val+l+r);
    return max(cur,root->val);
}
int maxPathSum(TreeNode* root)
{
    int res=INT_MIN;
    RecMaxPathSum(root, res);
    return res;
}


};