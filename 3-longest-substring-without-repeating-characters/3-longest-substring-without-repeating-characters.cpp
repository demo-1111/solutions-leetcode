class Solution {
public:
int lengthOfLongestSubstring(string &s)
{
    int res=1;
    int n=s.length();
    if(n==0) return 0;
    int arr[256];
    for(int i=0; i<256; i++)
        arr[i]=-1;
    arr[s[0]]=0;
    int c=1,pre=0;
    for(int i=1; i<n; i++) 
    {
        if(arr[s[i]]==-1)
        {
            arr[s[i]]=i;
            c++;
            res=max(res,c);
        }
        else
        {
            int loc=arr[s[i]];
            for(int k=pre; k<=loc; k++) 
                arr[s[k]]=-1;
            c=i-loc;
            pre=loc+1;
            arr[s[i]]=i;
        }
        // cout<<res<<" ";
    }
    // cout<<"\n";
    return res;
}
};