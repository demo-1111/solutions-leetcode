class Solution {
public:


vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    int n=strs.size();
    pair<string, int> arr[n];
    for(int i=0; i<n; i++)
    {
        string s=strs[i];
        sort(s.begin(), s.end());
        arr[i]={s,i};
    }
    sort(arr, arr+n);
    vector<vector<string>> res;
    for(int i=0; i<n-1; i++) 
    {
        vector<string> v;
        v.push_back(strs[arr[i].second]);
        while(i<n-1 && arr[i].first==arr[i+1].first)
        {
            
            v.push_back(strs[arr[i+1].second]);
            i++;
        }
        res.push_back(v);
    }
    if(n==1 || (n>=2 && arr[n-2].first!=arr[n-1].first))
        res.push_back({strs[arr[n-1].second]});
    return res;
}

};