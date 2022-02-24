class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        int n,i,j,k;
        unordered_set<int> s;
        n=nums.size();
        for(i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        nums.clear();
        for(auto x:s)
        {
            nums.push_back(x);
        }
        sort(nums.begin(),nums.end());
        
        n=nums.size();
        int ans=INT_MIN;
        i=0;
        while(i<n)
        {
            k=1;
            while(i+1<n&&nums[i+1]==nums[i]+1)
            {
                i++;
                k++;
            }
            i++;
            ans=max(ans,k);
        }
        return ans;
    }
};