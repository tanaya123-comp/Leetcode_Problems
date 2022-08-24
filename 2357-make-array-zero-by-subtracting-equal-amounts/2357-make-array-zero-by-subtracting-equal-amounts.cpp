class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int n,i;
        n=nums.size();
        
        unordered_set<int> st;
        
        for(i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                st.insert(nums[i]);
            }
        }
        
        return st.size();
    }
};