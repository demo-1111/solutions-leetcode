class Solution {
public:
string reverseVowels(string s)
{
    int l=0, h=s.length()-1;
    while(l<h)
    {
        while(l<h)
        {
            if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u' ||
                s[l]=='A' || s[l]=='E' || s[l]=='I' || s[l]=='O' || s[l]=='U')
                break;
            else 
                l++;
        }
        while(l<h)
        {
            if(s[h]=='a' || s[h]=='e' || s[h]=='i' || s[h]=='o' || s[h]=='u' ||
                s[h]=='A' || s[h]=='E' || s[h]=='I' || s[h]=='O' || s[h]=='U')
                break;
            else 
                h--;
        }
        if(l<h)
            swap(s[l++],s[h--]);
    }   
    return s; 
}

};