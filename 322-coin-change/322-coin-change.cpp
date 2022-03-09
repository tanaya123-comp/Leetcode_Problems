class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n,i,j;
        n=coins.size();
        int** dp;
        dp=new int*[n+1];
        for(i=0;i<=n;i++)
        {
            dp[i]=new int[amount+1];
        }
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=amount;j++)
            {
                 if(i==0&&j==0)
                {
                    dp[i][j]=0;
                     continue;
                }
                if(i==0)
                {
                    dp[i][j]=INT_MAX-1;
                    continue;
                }
                if(j==0)
                {
                    dp[i][j]=0;
                    continue;
                }
               
                if(coins[i-1]<=j)
                {
                    dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(dp[n][amount]==INT_MAX-1)
        {
            return -1;
        }
        return dp[n][amount];
    }
};