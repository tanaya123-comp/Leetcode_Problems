class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int siz,i,j,k,ans;
        siz=nums.size();
        ans=1;
        
        vector<vector<int> > dp(siz,vector<int> (2,1));
        
        for(i=1;i<siz;i++)
        {
            for(j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i][1]=max(dp[i][1],dp[j][0]+1);
                }
                else if(nums[j]>nums[i])
                {
                    dp[i][0]=max(dp[i][0],dp[j][1]+1);
                }
                
            }
            ans=max(ans,max(dp[i][0],dp[i][1]));
        }
        
        return ans;
    }
};