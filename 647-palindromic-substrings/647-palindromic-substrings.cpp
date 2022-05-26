class Solution {
public:
    int countSubstrings(string s) 
    {
        int len=s.length();
        int i,j,k;
        int ans=0;
        
        vector<vector<bool> > dp(len,vector<bool> (len,false));
        
        for(i=0;i<len;i++)
        {
            ans++;
            dp[i][i]=true;
        }
        
        for(i=0;i<len-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                ans++;
            }
        }
        
        for(k=3;k<=len;k++)
        {
            for(i=0;i<=len-k;i++)
            {
                j=i+k-1;
                if(s[i]==s[j]&&dp[i+1][j-1]==true)
                {
                    ans++;
                    dp[i][j]=true;
                }
            }
        }
        
        return ans;
    }
};