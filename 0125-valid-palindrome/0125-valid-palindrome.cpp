class Solution {
public:
int check(char c)
{
    if(c>='a' && c<='z') return 1;
    if(c>='A' && c<='Z') return 2;
    if(c>='0' && c<='9') return 3;
    return 0;
}
bool isPalindrome(string s)
{
    int l=0, h=s.length()-1;
    while(l<h)
    {
        int vl=check(s[l]);
        if(vl==0)
        {
            l++;
            continue;
        }
        int vh=check(s[h]);
        if(vh==0)
        {
            h--;
            continue;
        }
        int il, ih;
        if(vl==1) il=s[l]-'a';
        else if(vl==2) il=s[l]-'A';
        else il=s[l];

        if(vh==1) ih=s[h]-'a';
        else if(vh==2) ih=s[h]-'A';
        else ih=s[h];

        if(il!=ih)
            return false;
        l++; h--;
    }
    return true;    
}
};