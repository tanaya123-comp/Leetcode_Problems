class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n,i,j;
        n=nums.size();
        int sum=0;
        int ans=INT_MIN;
        for(i=0;i<n;i++)
        {
            sum=sum+nums[i];
            if(sum>ans)
            {
                ans=sum;
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        return ans;
    }
};