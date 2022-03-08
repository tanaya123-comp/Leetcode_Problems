class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m,n,i,j,siz;
        n=grid.size();
        m=grid[0].size();
        queue<pair<int,int> > q;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                }
            }
        }
        
        int ans=0;
        while(!q.empty())
        {
           
            siz=q.size();
             cout<<siz<<" ";
            while(siz--)
            {
                pair<int,int> p=q.front();
                q.pop();
                i=p.first;
                j=p.second;
                if((i-1)>=0&&grid[i-1][j]==1)
                {
                    grid[i-1][j]=2;
                    q.push(make_pair(i-1,j));
                }
                if((j-1)>=0&&grid[i][j-1]==1)
                {
                    grid[i][j-1]=2;
                    q.push(make_pair(i,j-1));
                }
                if((i+1)<n&&grid[i+1][j]==1)
                {
                    grid[i+1][j]=2;
                    q.push(make_pair(i+1,j));
                }
                if((j+1)<m&&grid[i][j+1]==1)
                {
                    grid[i][j+1]=2;
                    q.push(make_pair(i,j+1));
                }
            }
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
        if(ans==0)
        {
            return 0;
        }
        return ans-1;
        
    }
};