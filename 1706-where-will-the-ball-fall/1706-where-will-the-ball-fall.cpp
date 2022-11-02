class Solution {
public:
vector<int> findBall(vector<vector<int>>& grid) 
{
    int n=grid.size(), m=grid[0].size();
    vector<int> res(m);
    for(int col=0; col<m; col++) 
    {
        int cj=col, nj=col;
        for(int i=0; i<n; i++) 
        {
            if(grid[i][cj]==1) // nj+=grid[i][cj];
                nj++;
            else 
                nj--;
            if(nj<0 || nj>=m || grid[i][cj]!=grid[i][nj])
            {
                nj=-1;
                break;
            }
            cj=nj;
        }
        res[col]=nj;
    }
    return res;
}
};