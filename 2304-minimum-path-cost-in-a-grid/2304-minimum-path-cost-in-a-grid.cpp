class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int row,col,i,j,k;
        row=grid.size();
        col=grid[0].size();
        vector<vector<int> > dp(row,vector<int> (col,0));
        
        for(i=0;i<col;i++)
        {
            dp[0][i]=grid[0][i];
        }
        
        for(i=1;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                int x=moveCost[grid[i-1][0]][j]+dp[i-1][0];
               // int index=0;
                for(k=0;k<col;k++)
                {
                    if(x>moveCost[grid[i-1][k]][j]+dp[i-1][k])
                    {
                        x=moveCost[grid[i-1][k]][j]+dp[i-1][k];
                    }
                }
                dp[i][j]=x+grid[i][j];
            }
        }
        int ans=dp[row-1][0];
        for(i=0;i<col;i++)
        {
            ans=min(ans,dp[row-1][i]);
        }
        return ans;
        
    }
};