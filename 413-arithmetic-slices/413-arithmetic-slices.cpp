class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n,i,j,count,k;
        int numSubArrays=0;
        n=nums.size();
        if(n==1)
        {
            return 0;
        }
        i=0;
        while(i<n)
        {
            j=i;
            while((j+1)<n&&nums[j+1]-nums[j]==nums[i+1]-nums[i])
            {
                j++;
            }
            count=j-i+1;
            k=3;
            while(k<=count)
            {
              numSubArrays=numSubArrays+(count-k+1); 
                k++;
            }
            if(j+1==n)
            {
                break;
            }
            i=j;
        }
        return numSubArrays;
    }
};