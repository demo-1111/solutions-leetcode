struct triple
{
    int i,j,z;
    triple(int i, int j , int z):i(i),j(j),z(z){}
};
class Solution {
public:

int shortestPath(vector<vector<int>>& grid, int k)
{
    int n=grid.size(), m=grid[0].size(), res=0;
    if(n==1 && m==1) return 0;
    bool visited[n][m][k+1];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            for(int z=0; z<k+1; z++)
                visited[i][j][z]=false;
    queue<triple> q;
    q.push({0,0,k});
    visited[0][0][k]=true;
    int ar1[4]={1,-1,0,0};
    int ar2[4]={0,0,-1,1};
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0; i<sz; i++) 
        {
            int ci=q.front().i;
            int cj=q.front().j;
            int ck=q.front().z;
            q.pop();
            for(int u=0; u<4; u++) 
            {
                int ti=ci+ar1[u];
                int tj=cj+ar2[u];
                if(ti>=0 && ti<n && tj>=0 && tj<m)
                {
                    if(ti==n-1 && tj==m-1)
                        return res+1;
                    if(grid[ti][tj]==0 && visited[ti][tj][ck]==false)
                    {
                        q.push({ti,tj,ck});
                        visited[ti][tj][ck]=true;
                    }
                    if(grid[ti][tj]==1 && ck>=1 && visited[ti][tj][ck-1]==false)
                    {
                        q.push({ti,tj,ck-1});
                        visited[ti][tj][ck-1]=true;                   
                    }
                }
            }
        }
        res++;
    }
    return -1;
}

};