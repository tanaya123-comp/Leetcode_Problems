class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        unordered_map<int,int> left;
        unordered_map<int,int>::iterator it;
        long long sum=0;
        int l=0;
        int siz=nums.size();
        int ans=INT_MAX;
        for(l=0;l<siz&&sum<x;l++)
        {
            sum=sum+nums[l];
            left[sum]=l;
            if(sum==x)
            {
               // cout<<"here";
                ans=l+1;
            }
        }
        int r=siz-1;
        sum=0;
        while(r>=0)
        {
            sum=sum+nums[r];
            it=left.find(x-sum);
            if(it!=left.end()&&r>it->second)
            {
              //  cout<<it->second<<" "<<r<<"\n";
                ans=min(ans,it->second+1+siz-r);
            }
            if(sum==x)
            {
                ans=min(ans,siz-r);
            }
            r--;
            
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};