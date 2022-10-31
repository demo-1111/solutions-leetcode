class Solution {
public:
bool isToeplitzMatrix(vector<vector<int>>& mat)
{
    int n=mat.size(), m=mat[0].size();
    for(int i=0; i<n; i++) 
    {
        int ci=i, cj=0;
        int prev=mat[ci][cj];
        ci++; cj++;
        while(ci<n && cj<m)
        {
            if(mat[ci][cj]!=prev)
                return false;
            prev=mat[ci][cj];
            ci++; cj++;
        }
    }
    for(int j=1; j<m; j++) 
    {
        int ci=0, cj=j;
        int prev=mat[ci][cj];
        ci++; cj++;
        while(ci<n && cj<m)
        {
            if(mat[ci][cj]!=prev)
                return false;
            prev=mat[ci][cj];
            ci++; cj++;
        }
    }
    return true; 
}
};