class Solution {
public:
int longestPalindrome(vector<string>& words) 
{
    int n=words.size(), res=0;
    bool flag=false;
    unordered_map<string,int> um;
    for(int i=0; i<n; i++)
        um[words[i]]++;
    for(int i=0; i<n; i++) 
    {
        if(um[words[i]]>0)
        {
            if(words[i][0]==words[i][1])
            {
                if(um[words[i]]%2==0)
                {
                    res+=um[words[i]]*2;
                }
                else
                {
                    flag=true;
                    res+=(um[words[i]]-1)*2;
                }
            }
            else
            {
                string x="";
                x+=words[i][1];
                x+=words[i][0];
                if(um.find(x)!=um.end())
                {
                    res+=(min(um[x], um[words[i]]))*4;
                    um[x]=0;
                }
            }
            um[words[i]]=0;
        }
    }
    if(flag==true)
        res+=2;
    return res;
}
};