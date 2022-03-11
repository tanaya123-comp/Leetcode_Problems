class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m,n,i,j;
        n=grid.size();
        m=grid[0].size();
        queue<pair<int,int> > q;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        int k;
        while(!q.empty())
        {
            int siz=q.size();
            k=0;
            while(siz--)
            {
                pair<int,int> p=q.front();
                q.pop();
                i=p.first;
                j=p.second;
                if((j-1)>=0&&grid[i][j-1]==1)
                {
                    k++;
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                if((j+1)<m&&grid[i][j+1]==1)
                {
                    k++;
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
                if((i-1)>=0&&grid[i-1][j]==1)
                {
                    k++;
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                if((i+1)<n&&grid[i+1][j]==1)
                {
                    k++;
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
            }
            if(k>0)
            ans++;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};