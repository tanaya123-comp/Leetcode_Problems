class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int x=0;
        int len=nums.size();
        for(int i=0;i<=len;i++)
        {
            x=x^i;
        }
        for(int i=0;i<len;i++)
        {
            x=x^nums[i];
        }
        return x;
    }
};