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
int widthOfBinaryTree(TreeNode* root)
{
    queue<pair<TreeNode*, int>> q;
    q.push({root,0});
    int res=0;
    while(!q.empty())
    {
        int n=q.size(), mn, mx;
        for(int i=0; i<n; i++) 
        {
            if(i==0)
                mn=q.front().second;
            if(i==n-1)
                mx=q.front().second;
            
            TreeNode *cn=q.front().first;
            int ci=q.front().second;
            q.pop();
            
            int ind=ci-mn;
            if(cn->left!=NULL)
                q.push({cn->left, (long long)(2)*ind+1});    
            if(cn->right!=NULL)
                q.push({cn->right, (long long)(2)*ind+2});    
        }
        res=max(res,mx-mn+1);
    }    
    return res;
}
};