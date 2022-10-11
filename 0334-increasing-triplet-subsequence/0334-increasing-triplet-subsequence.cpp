class Solution
{
    public:
    void ceil(vector<int> &vec, int x)
    {
        int i=0, j=vec.size()-1;
        int ind=-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(vec[mid]==x) return;
            else if(vec[mid]<x) i=mid+1;
            else
            {
                ind=mid;
                j=mid-1;
            }
        }
        if(ind!=-1)
            vec[ind]=x;
    }
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        // int arr[n];
        // int res = 1;
        // for (int i = 0; i < n; i++)
        // {
        //     arr[i] = 1;
        //     for (int j = 0; j < i; j++)
        //     {
        //         if (nums[j] < nums[i])
        //         {
        //             arr[i] = max(arr[i], arr[j] + 1);
        //         }
        //     }
        //     res = max(res, arr[i]);
        //     if (res >= 3) return true;
        // }
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1; i<n; i++)
        {
            if(res[res.size()-1]<nums[i]) res.push_back(nums[i]);
            else ceil(res,nums[i]);
        }
        // cout<<res.size();
        if (res.size() >= 3) return true;
        return false;
    }
};