class Solution {
public:

bool isAnagram(string s, string t)
{
    int h[26]{0}, n=s.length(), m=t.length();
    if(n!=m) return false;
    for(int i=0; i<n; i++)
    {
        h[s[i]-'a']++;
        h[t[i]-'a']--;
    }
    for(int i=0; i<26; i++)
        if(h[i]!=0)
            return false;
    return true;    
}
};