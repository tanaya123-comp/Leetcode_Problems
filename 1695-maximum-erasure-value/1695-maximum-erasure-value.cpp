class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int siz=nums.size();
        long long i,j,sum;
        if(siz==1)
        {
            return nums[0];
        }
        long long ans=nums[0];
        for(i=1;i<siz;i++)
        {
            if(ans<nums[i])
            {
                ans=nums[i];
            }
            //ans=max(ans,nums[i]);
        }
        i=0;
        j=0;
        sum=0;
        map<int,int> mp;
        while(i<siz)
        {
            if(mp.find(nums[i])==mp.end())
            {
                sum=sum+nums[i];
                mp[nums[i]]=1;
            }
            else
            {
                while(mp.find(nums[i])!=mp.end())
                {
                    sum=sum-nums[j];
                    mp.erase(nums[j]);
                    j++;
                }
               // sum=sum-nums[j];
              //  mp.erase(nums[j]);
                //j++;
                sum=sum+nums[i];
                mp[nums[i]]=1;
            }
            if(ans<sum)
            {
                ans=sum;
            }
            //ans=max(ans,sum);
            i++;
        }
        return ans;
    }
};