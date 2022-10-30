class Solution {
public:
vector<int> getRow(int nr)
{
    nr++;
    // vector<vector<int>> res(nr);
    vector<vector<int>> res(2, vector<int>(nr));
    res[0]={{1}};
    if(nr==1) return res[(nr-1)%2];
    res[1]={{1,1}};
    if(nr==2) return res[(nr-1)%2];
    for(int i=2; i<nr; i++) 
    {
        vector<int> v(i+1);
        int k=0;
        v[k++]=1;
        for(int j=0; j<i-1; j++) 
        {
           v[k++]=res[(i+1)%2][j]+res[(i+1)%2][j+1];
        }
        v[k]=1;
        res[i%2]=v;
    }
    return res[(nr-1)%2];
}
};