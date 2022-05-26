class Solution {
public:
    
  
    
   
    
    
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1,0));
        int len=strs.size();
        int k;
	    for(k=0;k<len;k++) {
	           
		int zeros = count(strs[k].begin(), strs[k].end(), '0'); 
        int ones = strs[k].length() - zeros; 
		for(int i = m; i >= zeros; i--)
        {
            for(int j = n; j >= ones; j--)   
            {
               dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1); 
            }
        }
			
	}
	return dp[m][n];
    }
};