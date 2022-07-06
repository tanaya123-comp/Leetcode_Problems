class Solution {
public:
    int longestPalindrome(string s) {
        
        map<char,int> mp;
        for(auto x:s)
        {
            mp[x]++;
        }
        
        int odd=0;
        int ans=0;
        
        for(auto x:mp)
        {
            if(x.second%2==0)
            {
                ans=ans+x.second;
            }
            else
            {
                if(odd==0)
                {
                    ans=ans+x.second;
                    odd++;
                }
                else
                {
                    ans=ans+x.second-1;
                }
            }
        }
        
        return ans;
        
    }
};