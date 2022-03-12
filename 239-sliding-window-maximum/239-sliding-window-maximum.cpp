class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        deque<int> dq;
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            while(!dq.empty()&&dq.front()<=i-k)
            {
                dq.pop_front();
            }
            
            while(!dq.empty()&&nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            if(i>=k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
            
        }
        return ans;
    }
};