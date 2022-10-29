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
pair<int,int> fun(TreeNode *root, int &res)
{
    if(root==NULL) return {INT_MIN,1};
    pair<int,int> l=fun(root->left,res);
    pair<int,int> r=fun(root->right,res);
    if(root->val==l.first && root->val==r.first)
    {
        res=max(res, 1+l.second+r.second);
        return {root->val, 1+max(l.second,r.second)};
    }
    if(root->val==l.first)
    {
        res=max(res, 1+l.second);
        return {root->val, 1+l.second};
    }
    if(root->val==r.first)
    {
        res=max(res, 1+r.second);
        return {root->val, 1+r.second};
    }
    return {root->val, 1};
}
int longestUnivaluePath(TreeNode* root)
{
    int res=1;
    fun(root,res);
    return res-1;
}
};