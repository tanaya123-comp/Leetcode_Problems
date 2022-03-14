class Solution {
public:
    
void getAllPossibleSubsets(vector<int> &nums,int n,vector<int> subset,set<vector<int> > &allSubsets)
{
    if(n==0){
        sort(subset.begin(),subset.end());
        allSubsets.insert(subset);
        return;
    }
    
    getAllPossibleSubsets(nums,n-1,subset,allSubsets);
    
    subset.push_back(nums[n-1]);
    
    getAllPossibleSubsets(nums,n-1,subset,allSubsets);
}
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int> > allSubsets;
        
        vector<int> subset;
        
        getAllPossibleSubsets(nums,nums.size(),subset,allSubsets);
        
        vector<vector<int> > ans;
        
        for(auto x:allSubsets)
        {
            ans.push_back(x);
        }
        
        return ans;
        
    }
};