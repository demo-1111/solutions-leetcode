class Solution {
public:
vector<vector<int>> generate(int nr)
{
    vector<vector<int>> res(nr);
    res[0]={{1}};
    if(nr==1) return res;
    res[1]={{1,1}};
    if(nr==2) return res;
    for(int i=2; i<nr; i++) 
    {
        vector<int> v(i+1);
        int k=0;
        v[k++]=1;
        for(int j=0; j<i-1; j++) 
           v[k++]=res[i-1][j]+res[i-1][j+1];
        v[k]=1;
        res[i]=v;
    }
    return res;
}
};