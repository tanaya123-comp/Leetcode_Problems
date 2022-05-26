class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        int i,j,k;
        vector<vector<long> > dp(n+1,vector<long> (amount+1));
        
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=amount;j++)
            {
                if(i==0)
                {
                    dp[i][j]=INT_MAX;
                }
                if(j==0)
                {
                    dp[i][j]=0;
                }
                if(i>0&&j>0)
                {
                    if(j>=coins[i-1])
                    {
                        dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        if(dp[n][amount]==INT_MAX)
            return -1;
        
        return dp[n][amount];
    }
};