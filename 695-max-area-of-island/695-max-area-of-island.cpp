class Solution {
public:
    
    void getMaxArea(vector<vector<int>>& grid,int i,int j,int &k)
    {
        k++;
        
        grid[i][j]=0;
        
        if((i-1)>=0&&grid[i-1][j]==1)
        {
            getMaxArea(grid,i-1,j,k);
        }
        
        if((j-1)>=0&&grid[i][j-1]==1)
        {
            getMaxArea(grid,i,j-1,k);
        }
        
        if((i+1)<grid.size()&&grid[i+1][j]==1)
        {
            getMaxArea(grid,i+1,j,k);
        }
        
        if((j+1)<grid[0].size()&&grid[i][j+1]==1)
        {
            getMaxArea(grid,i,j+1,k);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n,m,i,j,k;
        n=grid.size();
        m=grid[0].size();
        
        int ans=0;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    k=0;
                    getMaxArea(grid,i,j,k);
                    ans=max(ans,k);
                }
            }
        }
        return ans;
    }
};