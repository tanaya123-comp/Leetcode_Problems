class Solution {
public:
    
    vector<vector<int> > ans;
    set<vector<int> > s;
    int n;
    
    void solve(int target,int sum,vector<int> vec,int i,vector<int>& cand)
    {
        if(i==n)
        {
            return;
        }
        if(sum==target)
        {
            cout<<sum<<"\n";
            if(s.find(vec)==s.end())
            {
                s.insert(vec);
            }
        }
        if(sum+cand[i]<=target)
        {
            vec.push_back(cand[i]);
            solve(target,sum+cand[i],vec,i,cand);
            vec.pop_back();
            solve(target,sum,vec,i+1,cand);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        n=candidates.size();
        vector<int> vec;
        solve(target,0,vec,0,candidates);
        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
        
    }
};