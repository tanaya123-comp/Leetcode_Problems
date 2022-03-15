class Solution {
public:
    
    vector<vector<int> > allPermutations;
    
    void permute(vector<int> &nums,int low,int end)
    {
        if(low==end)
            allPermutations.push_back(nums);
        
        for(int i=low;i<=end;i++)
        {
            swap(nums[low],nums[i]);
            
            permute(nums,low+1,end);
            
            swap(nums[low],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        permute(nums,0,nums.size()-1);
        
        return allPermutations;
        
    }
};