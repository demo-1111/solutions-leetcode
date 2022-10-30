class Solution {
public:
uint32_t reverseBits(uint32_t n)
{
    uint32_t x=0;
    string s="";
    while(n>0)
    {
        s+=(n%2 + '0');
        n/=2;
    }
    while(s.length()!=32)
        s+='0';
    long long mul=1;
    for(int i=31; i>=0; i--) 
    {
        x+=mul*(s[i]-'0');
        mul*=2;
    }
    return x; 
}
};