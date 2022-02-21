class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n,i,j,k;
        n=nums.size();
        i=0;
        j=n-1;
        for(k=0;k<=j;k++)
        {
            if(nums[k]==2)
            {
                swap(nums[k],nums[j]);
                j--;
                k--;
            }
            else if(nums[k]==0&&k>i)
            {
                swap(nums[k],nums[i]);
                i++;
                k--;
            }
        }
        
    }
};