class Solution {
public:
    
    void numOfIslands(vector<vector<char>>& grid,int i,int j)
    {
        grid[i][j]='0';
        
        if((i-1)>=0&&grid[i-1][j]=='1')
        {
            numOfIslands(grid,i-1,j);
        }
        
        if((j-1)>=0&&grid[i][j-1]=='1')
        {
            numOfIslands(grid,i,j-1);
        }
        
        if((i+1)<grid.size()&&grid[i+1][j]=='1')
        {
            numOfIslands(grid,i+1,j);
        }
        
        if((j+1)<grid[0].size()&&grid[i][j+1]=='1')
        {
            numOfIslands(grid,i,j+1);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n,m,i,j;
        n=grid.size();
        m=grid[0].size();
        
        int num_of_islands=0;
        
        for(i=0;i<n;i++)
        {
         for(j=0;j<m;j++)
         {
             if(grid[i][j]=='1')
             {
                num_of_islands++;
             numOfIslands(grid,i,j);
            }
             
         }
        }
        
        return num_of_islands;
    }
};