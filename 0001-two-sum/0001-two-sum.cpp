class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> res(2);
    int n=nums.size();
    int l=0, r=n-1, cur=0;
    pair<int,int> arr[n];
    for(int i=0; i<n; i++)
        arr[i]={nums[i],i};
    sort(arr, arr+n);
    while(l<r)
    {
        cur=arr[l].first+arr[r].first;
        if(cur<target) l++;
        else if(cur>target) r--;
        else
        {
            res[0]=arr[l].second;
            res[1]=arr[r].second;
            break;
        }
    }    
    return res;
}
};