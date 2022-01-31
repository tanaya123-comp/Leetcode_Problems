class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int n,m,i,j;
        n=accounts.size();
        m=accounts[0].size();
        int ans=INT_MIN;
        for(i=0;i<n;i++)
        {
            int sum=0;
            for(j=0;j<m;j++)
            {
                sum=sum+accounts[i][j];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};