class Solution {
public:
    
    int singleNonDuplicate(vector<int>& nums) 
    {
        int low,high,mid;
        low=0;
        high=nums.size()-2;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==nums[mid^1])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return nums[low];
    }
    
};