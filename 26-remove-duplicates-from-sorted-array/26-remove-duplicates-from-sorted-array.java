class Solution {
    public int removeDuplicates(int[] nums) {
        
        int length,i,j;
        length=nums.length;
        i=0;
        j=0;
        while(j<length)
        {
            while((j+1)<length&&nums[j]==nums[j+1])
            {
                j++;
            }
            nums[i]=nums[j];
            i++;
            j++;
        }
        return i;
        
    }
}