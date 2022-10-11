class Solution {
public:
void fun(vector<vector<int>> &res, vector<int> &nums, int n, int k)
{   
    if(k==n)
    {
        res.push_back(nums);
        return;
    }
    for(int i=k; i<n; i++) 
    {
        swap(nums[k],nums[i]);
        fun(res,nums,n,k+1);
        swap(nums[k],nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    int n=nums.size();
    fun(res, nums, n, 0);
    return res;
}
};