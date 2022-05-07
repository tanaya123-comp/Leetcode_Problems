class Solution {
public:
    int uniquePaths(int m, int n) 
    {
       vector<vector<int> > dp(m, vector<int> (n,-1));

     for (int r=0; r < m; r++) {
         for (int c=0; c < n; c++) {
             if (r==0 || c == 0) { 
                 dp[r][c] = 1;
                 continue;
             }
             dp[r][c] = dp[r-1][c] + dp[r][c-1];
         }
     }
     return dp[m-1][n-1];
    }
};