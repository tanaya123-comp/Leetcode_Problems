class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n=nums.size();
        int x=nums[0];
        for(int i=1;i<n;i++)
        {
            x=x^nums[i];
        }
        return x;
    }
};