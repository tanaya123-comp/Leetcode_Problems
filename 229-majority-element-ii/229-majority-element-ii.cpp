class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n,i,j;
        n=nums.size();
        vector<int> ans;
        int first,second;
        int count1=0;
        int count2=0;
        first=0;
        second=0;
        for(i=0;i<n;i++)
        {
            if(first==nums[i])
            {
                count1++;
            }
            else if(second==nums[i])
            {
                count2++;
            }
            else if(count1==0)
            {
                first=nums[i];
                count1++;
            }
            else if(count2==0)
            {
                second=nums[i];
                count2++;
            }else
            {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        cout<<first<<" "<<second<<"\n";
        for(i=0;i<n;i++)
        {
            if(first==nums[i])
            {
                cout<<first<<" "<<nums[i];
                count1++;
            }
            else if(second==nums[i])
            {
              //  cout<<second<<
                count2++;
            }
        }
        cout<<count1<<" "<<count2<<"\n";
        if(count1>(n/3))
        {
            ans.push_back(first);
        }
        if(count2>(n/3))
        {
            ans.push_back(second);
        }
            return ans;
        
    }
};