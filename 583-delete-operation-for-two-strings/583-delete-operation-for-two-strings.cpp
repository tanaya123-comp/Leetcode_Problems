class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int len1,len2;
        len1=word1.length();
        len2=word2.length();
        int i,j;
        vector<vector<int> > dp(len1+1,vector<int> (len2+1,0));
        
        for(i=0;i<=len1;i++)
        {
            for(j=0;j<=len2;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
                else if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int len=dp[len1][len2];
    //    cout<<len<<"\n";
        return len1+len2-2*len;
        
    }
};