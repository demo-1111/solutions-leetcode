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
void RecpathSum(TreeNode *root, long long targetSum, int &res)
{
    if(root==NULL) return;
    long long cur=targetSum-root->val;
    if(cur==0)
        res++;
    RecpathSum(root->left, cur, res);
    RecpathSum(root->right, cur, res);
}
int pathSum(TreeNode* root, int targetSum)
{
    if(root==NULL) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int res=0;
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0; i<n; i++) 
        {
            TreeNode* cur=q.front();
            q.pop();
            RecpathSum(cur,(long long)targetSum, res);
            if(cur->left!=NULL) q.push(cur->left);
            if(cur->right!=NULL) q.push(cur->right);
        }
    }
    return res;    
}
};