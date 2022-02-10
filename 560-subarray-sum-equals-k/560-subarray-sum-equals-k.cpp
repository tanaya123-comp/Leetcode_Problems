class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int siz,i,j;
        siz=nums.size();
        unordered_map<int,int> mp;
        int ans=0;
        int sum=0;
        for(i=0;i<siz;i++)
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