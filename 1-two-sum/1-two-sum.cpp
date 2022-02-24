class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int siz,i,j;
        siz=nums.size();
        multimap<int,int> mp;
        multimap<int,int>::iterator it;
        vector<int> vec;
        for(i=0;i<siz;i++)
        {
            mp.insert({nums[i],i});
        }
        // for(auto x:mp)
        // {
        //     cout<<x.first<<" "<<x.second<<"\n";
        // }
        for(i=0;i<siz;i++)
        {
            it=mp.find(target-nums[i]);
            if(it!=mp.end())
            {
                if(target-nums[i]!=nums[i])
                {
                    vec.push_back(i);
                    vec.push_back(it->second);
                    break;
                }
                else
                {
                    cout<<"here";
                    it++;
                    if(it!=mp.end()&&it->first==target-nums[i])
                    {
                        vec.push_back(i);
                        vec.push_back(it->second);
                        break; 
                    }
                   
                }
                
            }
        }
        return vec;
        
    }
};