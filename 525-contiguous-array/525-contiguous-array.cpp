class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int n,i,j;
        n=nums.size();
        
        map<int,int> mp;
        
        int sum=0;
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                sum=sum+1;
            }
            else
            {
                sum=sum-1;
            }
            if(sum==0)
            {
                ans=max(ans,i+1);
            }
            
            if(mp.find(sum)!=mp.end())
            {
                ans=max(ans,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        
        return ans;
        
    }
};