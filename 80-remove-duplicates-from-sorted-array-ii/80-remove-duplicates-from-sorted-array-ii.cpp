class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n,i,j,k;
        n=nums.size();
        
        i=0;
        j=0;
        while(i<n)
        {
            nums[j]=nums[i];
            j++;
            if((i+1)<n&&nums[i+1]==nums[i])
            {
                nums[j]=nums[i];
                j++;
                i++;
                
                while((i+1)<n&&nums[i+1]==nums[i])
                {
                    i++;
                }
                i++;
            }
            else
            {
                i++;
            }
        }
        return j;
        
    }
};