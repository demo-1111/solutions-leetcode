class Solution {
public:
int trailingZeroes(int n)
{
    int res=0;
    unsigned long long x=5;
    while((n/x)>0)
    {
        res+=(n/x);
        x*=5;
    }
    return res;
}
};