class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> nextGreRes;
        stack<int> s;
        int i,j;
        int m=nums2.size();
        int n=nums1.size();
        vector<int> vec(m);
        vec[m-1]=-1;
        s.push(nums2[m-1]);
        for(int i=m-2;i>=0;i--)
        {
            if(s.empty())
            {
                vec[i]=-1;
                s.push(nums2[i]);
            }
            else
            {
                while(!s.empty()&&s.top()<nums2[i])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    vec[i]=-1;
                    s.push(nums2[i]);
                }
                else
                {
                    vec[i]=s.top();
                    s.push(nums2[i]);
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    nextGreRes.push_back(vec[j]);
                    break;
                }
            }
        }
        
        return nextGreRes;
    }
};