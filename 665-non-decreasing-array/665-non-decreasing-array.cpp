class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n,i,j,err;
        n=nums.size();
        err=0;
        for(i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                if(err++||(i>1&&i<n-1&&nums[i-2]>nums[i]&&nums[i-1]>nums[i+1]))
                {
                    return false;
                }
            }
            
        }
        return true;
    }
};