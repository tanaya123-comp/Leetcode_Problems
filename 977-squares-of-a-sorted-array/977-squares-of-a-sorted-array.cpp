class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int siz=nums.size();
        int i,j;
        for(i=0;i<siz;i++)
        {
            if(nums[i]>=0)
                break;
        }
        j=i;
        for(i=0;i<siz;i++)
        {
            nums[i]=nums[i]*nums[i];
        }
        if(j==0)
        {
            return nums;
        }
        vector<int> ans;
        i=j-1;
        while(i>=0&&j<siz)
        {
            if(nums[i]<nums[j])
            {
                ans.push_back(nums[i]);
                i--;
            }else
            {
                ans.push_back(nums[j]);
                j++;
            }
            
        }
        while(i>=0)
        {
            ans.push_back(nums[i]);
            i--;
        }
        
        while(j<siz)
        {
            ans.push_back(nums[j]);
                j++;   
        }
        return ans;
        
        
        
        
    }
};