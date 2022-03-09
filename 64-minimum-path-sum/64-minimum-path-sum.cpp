class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n,m,i,j;
        n=grid.size();
        m=grid[0].size();
        for(i=1;i<m;i++)
        {
            grid[0][i]=grid[0][i]+grid[0][i-1];
        }
        for(i=1;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int x,y;
                if((i-1)>=0)
                {
                    x=grid[i-1][j];
                }
                else
                {
                    x=INT_MAX;
                }
                if((j-1)>=0)
                {
                    y=grid[i][j-1];
                }
                else
                {
                    y=INT_MAX;
                }
                grid[i][j]=grid[i][j]+min(x,y);
            }
        }
        return grid[n-1][m-1];
    }
};