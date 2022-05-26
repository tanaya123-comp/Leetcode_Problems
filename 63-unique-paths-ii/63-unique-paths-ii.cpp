class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {    
        
        int n,m,i,j,k;
        n=obstacleGrid.size();
        m=obstacleGrid[0].size();
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                obstacleGrid[i][j]=1-obstacleGrid[i][j];
            }
        }
        vector<vector<long long> > dp(n,vector<long long> (m,0));
        
        if(obstacleGrid[0][0]==1)
            dp[0][0]=1;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                     if((i-1)>=0)
                    {
                        if(obstacleGrid[i-1][j]==1)
                        {
                            dp[i][j]=(dp[i][j]+dp[i-1][j])%2000000009;
                        }
                    }
                    if((j-1)>=0)
                    {
                        if(obstacleGrid[i][j-1]==1)
                        {
                            dp[i][j]=(dp[i][j]+dp[i][j-1])%2000000009;
                        }
                    }   
                }
                
            }
        }
        
       
        
        return dp[n-1][m-1];
    }
};