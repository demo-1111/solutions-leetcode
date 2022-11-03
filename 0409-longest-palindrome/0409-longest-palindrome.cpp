class Solution {
public:
int longestPalindrome(string s)
{
    int arr[128]{0}, n=s.length(), res=0;
    bool flag=false;
    for(int i=0; i<n; i++)
        arr[s[i]]++;
    for(int i=0; i<128; i++) 
    {
        if(arr[i]%2==0)
            res+=arr[i];    
        else
        {
            res+=(arr[i]-1);
            flag=true;
        }
    }
    if(flag==true)
        res+=1;
    return res;
}

};