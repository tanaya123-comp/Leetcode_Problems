class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit,i,j;
        if(n==1)
        {
            return 0;
        }
        profit=INT_MIN;
        j=prices[0];
        for(i=1;i<n;i++)
        {
            j=min(j,prices[i]);
            profit=max(profit,prices[i]-j);
        }
        return profit;
    }
};