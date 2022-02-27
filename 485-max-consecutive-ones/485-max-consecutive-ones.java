class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        
        int length,i,k;
        length=nums.length;
        i=0;
        int ans=0;
        while(i<length)
        {
            if(nums[i]==0)
            {
                i++;
            }
            else
            {
                k=0;
                while(i<length&&nums[i]==1)
                {
                    i++;
                    k++;
                }
                ans=Math.max(k,ans);
            }
        }
        return ans;
        
    }
}