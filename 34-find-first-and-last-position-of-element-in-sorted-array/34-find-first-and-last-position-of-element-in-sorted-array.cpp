class Solution {
public:
    
    int getFirstIndex(vector<int>& nums, int target)
    {
        int low,mid,high;
        low=0;
        high=nums.size()-1;
        
        int ans=-1;
        while(low<=high)
        {
             mid=(low+high)/2;
            
            if(target==nums[mid])
            {
                ans=mid;
                high=mid-1;
            }
            else if(target<nums[mid])
            {
                 high=mid-1;
               
            }
            else
            {
                low=mid+1;
            }
        }
        //cout<<ans<<"\n";
        return ans;
    }
    
     int getLastIndex(vector<int>& nums, int target)
    {
        int low,mid,high;
        low=0;
        high=nums.size()-1;
        
        int ans=-1;
        while(low<=high)
        {
             mid=(low+high)/2;
            
            if(target==nums[mid])
            {
                ans=mid;
                low=mid+1;
            }
            else if(target<nums[mid])
            {
                 high=mid-1;
            }
            else
            {
               low=mid+1;
            }
        }
         //cout<<ans;
        return ans;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int low,mid,high;
        low=0;
        high=nums.size()-1;
        
        if(nums.size()==0)
        {
            return {-1,-1};
        }
        
        vector<int> ans(2);
        ans[0]=getFirstIndex(nums,target);
        ans[1]=getLastIndex(nums,target);
        return ans;
    }
};