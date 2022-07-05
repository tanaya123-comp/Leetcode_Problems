class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st;
        int siz,i,j,k;
        siz=nums.size();
        
        for(i=0;i<siz;i++)
        {
            st.insert(nums[i]);
        }
        int ans=0;
        for(i=0;i<siz;i++)
        {
            if(st.count(nums[i]-1)==0)
            {
                k=0;
                j=nums[i];
                while(st.count(j))
                {
                    k++;
                    j++;
                }
                ans=max(ans,k);
            }
        }
        return ans;
    }
};