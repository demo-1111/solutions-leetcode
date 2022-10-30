//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
struct triple
{
    int i,j,w;
    triple(int i, int j, int w):i(i),j(j),w(w){}
};
int shotestPath(vector<vector<int>> mat, int n, int m, int k)
{
    if(n==1 && m==1 && (mat[0][0]==0 || k>=1)) return 0;
    bool visited[n][m][k+1];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            for(int l=0; l<k+1; l++)
                visited[i][j][l]=false;
    queue<triple> q;
    q.push({0,0,k});
    int res=0;
    while(!q.empty())
    {
        int size=q.size();
        res++;
        while(size--)
        {
            int i=q.front().i, j=q.front().j, w=q.front().w;
            q.pop();
            visited[i][j][w]=true;
            int ar1[4]={1,-1,0,0}; 
            int ar2[4]={0,0,-1,1};
            for(int l=0; l<4; l++) 
            {
                int ti = i + ar1[l], tj = j + ar2[l], tw=w;
                if(ti>=0 && ti<n && tj>=0 && tj<m)
                {
                    if(mat[ti][tj]==0 && visited[ti][tj][tw]==false)
                    {
                        if(ti==n-1 && tj==m-1) return res;
                        q.push({ti,tj,tw});
                        visited[ti][tj][tw]=true;
                    }
                    else if(mat[ti][tj]==1 && tw>=1 && visited[ti][tj][tw-1]==false)
                    {
                        if(ti==n-1 && tj==m-1) return res;
                        q.push({ti,tj,tw-1});                       
                        visited[ti][tj][tw-1]=true;
                    }
                }
            } 
        }
    }
    return -1;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends