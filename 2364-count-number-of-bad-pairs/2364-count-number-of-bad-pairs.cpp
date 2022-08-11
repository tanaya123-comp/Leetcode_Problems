class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long n=nums.size();
        long long total_pairs=((n*(n-1))/2);
        
        unordered_map<long,long> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]-i]++;
        }
        
        long long good_pairs=0;
        
        for(auto x:mp)
        {
            good_pairs=good_pairs+((x.second*(x.second-1))/2);
        }
        
       // cout<<total_pairs<<" "<<good_pairs<<"\n";
        
        return total_pairs-good_pairs;
    }
};