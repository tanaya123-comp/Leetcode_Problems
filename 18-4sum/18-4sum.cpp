class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     int n,i,j,l,r;
        n=nums.size();
        long long sum;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(i=0;i<n-3;i++)
        {
            for(j=i+1;j<n-2;j++)
            {
                l=j+1;
                r=n-1;
                while(l<r)
                {
                    sum=nums[i]+nums[j];
                    sum=sum+nums[l]+nums[r];
                    if(sum==target)
                    {
                        vector<int> vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[l]);
                        vec.push_back(nums[r]);
                        sort(vec.begin(),vec.end());
                        s.insert(vec);
                        l++;
                    }
                    else if(sum<target)
                    {
                        l++;
                    }
                    else if(sum>target)
                    {
                        r--;
                    }
                }
            }
        }
        vector<vector<int> > ans;
        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};