class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int size,i,j,ans;
        unordered_map<int,int> mp;
        size=nums.size();
        for(auto x: nums)
        {
            mp[x]++;
        }
        
        ans=0;
        for(auto x:mp)
        {
            if(k==0)
            {
                if(x.second>1)
                {
                    ans++;
                }
            }
            else if(mp.find(x.first+k)!=mp.end())
            {
                ans++;
            }
        }
        return ans;
        
    }
};