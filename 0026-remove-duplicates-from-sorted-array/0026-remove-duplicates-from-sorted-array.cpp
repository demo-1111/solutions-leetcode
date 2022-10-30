class Solution {
public:
int removeDuplicates(vector<int>& nums)
{
    bool h[201]{false};
    int n=nums.size();
    for(int i=0; i<n; i++)
        h[nums[i]+100]=true;
    int res=0;
    for(int i=0; i<201; i++) 
    {
        if(h[i]==true)
            nums[res++]=i-100;
    }
    return res;
}
};