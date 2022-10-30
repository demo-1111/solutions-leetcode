class Solution {
public:
// int mySqrt(int x)
// {
//     unsigned long long int i=0;
//     while(i*i <= x)
//         i++;
//     return i-1;
// }
    
int mySqrt(int x)
{
    unsigned long long res=0, l=0, r=x, m, cur;
    while(l<=r)
    {
        m=l+(r-l)/2;
        cur=m*m;
        if(cur==x) return m;
        else if(cur<x)
        {
            l=m+1;
            res=m;
        }
        else
            r=m-1;
    }
    return res;
}

};