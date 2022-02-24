class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.length()==0)
        {
            return 0;
        }
        int ans=1;
        int n=s.length();
        int i,j,k;
        i=0;
        j=0;
        unordered_map<int,int> vec;
        while(i<=j&&j<n)
        {
            vec[s[j]]++;
            if(vec[s[j]]==1)
            {
                j++;
            }
            else
            {
                ans=max(ans,j-i);
                while(i<j&&vec[s[i]]==1)
                {
                    vec[s[i]]--;
                    i++;
                }
                vec[s[i]]--;
                i++;
                j++;
            }   
        }
        if(i<j)
        {
            ans=max(ans,j-i);
        }
        return ans;
    }
};