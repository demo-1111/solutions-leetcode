class Solution {
public:
int climbStairs(int n)
{
    n++;
    // 1 1 2 3 5;
    if(n==1 || n==2) return 1;
    int prev=1, cur=1;
    for(int i=0; i<n-2; i++) 
    {
        int temp=cur;
        cur+=prev;
        prev=temp;
    }
    return cur;
}
};