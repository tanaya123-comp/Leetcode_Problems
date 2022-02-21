class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n,i,j;
        n=nums.size();
        i=n-1;
        while(i>0&&nums[i-1]>=nums[i])
        {
            i--;
        }
        if(i==0)
        {
         sort(nums.begin(),nums.end());   
        }
        else
        {
            i=i-1;
            j=n-1;
            while(j>i&&nums[j]<=nums[i])
            {
                j--;
            }
            swap(nums[j],nums[i]);
            i=i+1;
            j=n-1;
            while(i<j)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
    }
};