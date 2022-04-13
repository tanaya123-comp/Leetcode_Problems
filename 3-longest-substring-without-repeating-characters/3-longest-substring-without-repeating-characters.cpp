class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        int i,j,k;
        vector<int> mp(256,0);
        int ans=0;
        i=0;
        j=0;
        while(i<n)
        {
          
            if(mp[s[i]]==0)
            {
                mp[s[i]]++;
                 ans=max(ans,i-j+1);
                i++;
            }
            else
            {
                while(j<=i)
                {
                    if(mp[s[j]]==1)
                    {
                        mp[s[j]]--;
                        break;
                    }
                    j++;
                }
                j++;
            }
           
            
        }
        
        return ans;
    }
};