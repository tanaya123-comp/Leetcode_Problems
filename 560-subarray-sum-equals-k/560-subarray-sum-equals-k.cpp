class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> mp;
        int n,i,ans,sum;
        n=nums.size();
        ans=0;
        sum=0;
        for(i=0;i<n;i++)
        {
            sum=sum+nums[i];
            if(sum==k)
            {
             ans++;   
            }
            if(mp.find(sum-k)!=mp.end())
            {
                ans=ans+mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};