class Solution {
public:
    string longestPalindrome(string s) {
        
        int n,i,j,k;
        n=s.length();
        vector<vector<bool> > dp(n,vector<bool> (n,false));
        int len=1;
        int start=0;
        for(i=0;i<n;i++)
        {
            dp[i][i]=true;
        }
        for(i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                len=2;
                start=i;
            }
        }
        
        for(i=3;i<=n;i++)
        {
            for(j=0;j<=n-i;j++)
            {
                k=j+i-1;
                
                if(s[j]==s[k]&&dp[j+1][k-1]==true)
                {
                    if(len<i)
                    {
                        len=i;
                        start=j;
                    }
                    dp[j][k]=true;
                }
            }
        }
        
        return s.substr(start,len);
        
    }
};