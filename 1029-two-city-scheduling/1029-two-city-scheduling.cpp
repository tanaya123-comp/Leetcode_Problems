class Solution {
public:
    
    int dp[101][101][101];
    
    int getMinimumCosts(vector<vector<int>>& costs,int na,int nb,int n)
    {
        if(n==0)
            return 0;
        
        int cityA,cityB;
        
        if(dp[na][nb][n]!=-1)
            return dp[na][nb][n];
        
        if(na>0)
        {
            cityA=getMinimumCosts(costs,na-1,nb,n-1)+costs[n-1][0];
        }
        else
        {
            cityA=INT_MAX;
        }
        if(nb>0)
        {
            cityB=getMinimumCosts(costs,na,nb-1,n-1)+costs[n-1][1];
        }
        else
        {
            cityB=INT_MAX;
        }
        return dp[na][nb][n]=min(cityA,cityB);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        int na,nb,total_people;
        total_people=costs.size();
        sort(costs.begin(),costs.end());
        na=total_people/2;
        nb=total_people/2;
        
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=100;j++)
            {
                for(int k=0;k<=100;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        
        return getMinimumCosts(costs,na,nb,total_people);
        
    }
};