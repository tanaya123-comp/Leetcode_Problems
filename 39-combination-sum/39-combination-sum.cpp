class Solution {
public:
    
    vector<vector<int> > allCombinations;
    set<vector<int> > uniqueCombinations;
    
    void combinationSumRec(vector<int> &candidates,int target,int sum,vector<int> combination,int n)
    {
        if(sum==target)
        {
            uniqueCombinations.insert(combination);
            return;
        }
        if(n==0)
        {
            return;
        }
        if(sum>target)
        {
            return;
        }
        
        combinationSumRec(candidates,target,sum,combination,n-1);
        
        combination.push_back(candidates[n-1]);
        
        combinationSumRec(candidates,target,sum+candidates[n-1],combination,n);
        
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        
        vector<int> combination;
        
        combinationSumRec(candidates,target,0,combination,candidates.size());
        
        for(auto x:uniqueCombinations)
        {
            allCombinations.push_back(x);
        }
        
        return allCombinations;
    }
};