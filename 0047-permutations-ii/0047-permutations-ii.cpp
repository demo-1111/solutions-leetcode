class Solution {
public:

void fun(vector<vector<int>> &res, vector<int> &nums, int n, int k)
{   
    if(k==n)
    {
        res.push_back(nums);
        return;
    }
    unordered_set<int> us;
    for(int i=k; i<n; i++) 
    {
        if(us.find(nums[i])==us.end())
        {
            us.insert(nums[i]);
            swap(nums[k],nums[i]);
            fun(res,nums,n,k+1);
            swap(nums[k],nums[i]);
        }
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums)
{
    vector<vector<int>> res;
    int n=nums.size();
    fun(res, nums, n, 0);
    return res;
}

};