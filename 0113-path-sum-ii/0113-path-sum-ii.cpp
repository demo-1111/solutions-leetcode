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
void pathSum(TreeNode* root, int targetSum, vector<vector<int>> &res, vector<int> &v)
{
    if(root==NULL) return;
    int cur=targetSum-root->val;
    v.push_back(root->val);
    if(root->left==NULL && root->right==NULL && cur==0)
        res.push_back(v);
    pathSum(root->left, cur, res, v);
    pathSum(root->right, cur, res, v);
    v.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum)
{
    vector<vector<int>> res;
    vector<int> v;
    pathSum(root,targetSum,res,v);
    return res;       
}
};