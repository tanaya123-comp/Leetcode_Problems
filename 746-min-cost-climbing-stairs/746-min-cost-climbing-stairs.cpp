class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n,i,j;
        n=cost.size();
        
        vector<int> dp(n+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(i=2;i<=n;i++)
        {
            if(i<n)
                dp[i]=min(dp[i-1]+cost[i],dp[i-2]+cost[i]);
            else
                dp[i]=min(dp[i-1],dp[i-2]);
        }
        
        return dp[n];
        
    }
};