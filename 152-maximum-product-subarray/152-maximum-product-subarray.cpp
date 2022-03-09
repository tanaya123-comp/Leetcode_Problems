class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int i,minProd,maxProd,n,ans;
        n=nums.size();
        minProd=nums[0];
        maxProd=nums[0];
        ans=nums[0];
        for(i=1;i<n;i++)
        {
            if(nums[i]<0)
            {
                swap(minProd,maxProd);
            }
            
            minProd=min(minProd*nums[i],nums[i]);
            maxProd=max(maxProd*nums[i],nums[i]);
            
            ans=max(ans,max(minProd,maxProd));
        }
        return ans;
    }
};