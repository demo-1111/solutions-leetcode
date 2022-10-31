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
TreeNode* fun(vector<int> &arr, int l, int h)
{                                  
    if(l<=h)
    {
        int m=(l+h)/2;
        TreeNode *temp = new TreeNode(arr[m]);
        temp->left=fun(arr, l, m-1);
        temp->right=fun(arr, m+1, h);
        return temp;
    }       
    return NULL;                  
}
TreeNode* sortedArrayToBST(vector<int>& arr)
{
    return fun(arr, 0, arr.size()-1);
}
    
    
    
    
    
    
    
    
    
};