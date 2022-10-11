class Solution
{
    public:
    void ceil(int tail[], int x, int len)
    {
        int i=0, j=len-1, ind=-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(tail[mid]==x) return;
            else if(tail[mid]<x) i=mid+1;
            else
            {
                ind=mid;
                j=mid-1;
            }
        }
        if(ind!=-1)
            tail[ind]=x;
    }
    bool increasingTriplet(vector<int> &a)
    {
        int n = a.size();
        int tail[n];
        int len=0;
        tail[len++]=a[0];
        for(int j=1; j<n; j++)
        {
            if(tail[len-1]<a[j])
            
                tail[len++]=a[j];
            else
                ceil(tail, a[j], len);
        }
        if (len >= 3) return true;
        return false;
    }
};