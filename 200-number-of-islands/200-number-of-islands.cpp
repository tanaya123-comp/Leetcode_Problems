class Solution {
public:
    
void dfs(vector<vector<char>>& grid,vector<vector<bool> > &visited,int i,int j)
    {
        visited[i][j]=true;
        if((i-1)>=0&&visited[i-1][j]==false&&grid[i-1][j]=='1')
        {
            dfs(grid,visited,i-1,j);
        }
        if((i+1)<grid.size()&&visited[i+1][j]==false&&grid[i+1][j]=='1')
        {
            dfs(grid,visited,i+1,j);
        }
        if((j-1)>=0&&visited[i][j-1]==false&&grid[i][j-1]=='1')
        {
            dfs(grid,visited,i,j-1);
        }
        if((j+1)<grid[0].size()&&visited[i][j+1]==false&&grid[i][j+1]=='1')
        {
            dfs(grid,visited,i,j+1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
       int n,m,i,j,ans;
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool> > visited(n,vector<bool> (m,false));
        ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]=='1'&&visited[i][j]==false)
                {
                    ans++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return ans;
    }
};