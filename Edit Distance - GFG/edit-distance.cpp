// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  int dp[105][105];
  
    int editDistanceDP(string s,string t,int n,int m)
    {
        if(n==0)
        {
            return dp[n][m]=m;
        }
        if(m==0)
        {
            return dp[n][m]=n;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(s[n-1]==t[m-1])
        {
            return dp[n][m]=editDistanceDP(s,t,n-1,m-1);
        }
        else
        {
            return dp[n][m]=min(1+editDistanceDP(s,t,n,m-1),min(1+editDistanceDP(s,t,n-1,m),1+editDistanceDP(s,t,n-1,m-1)));
        }
    }
  
    int editDistance(string s, string t) {
        // Code here
        for(int i=0;i<=104;i++)
        {
            for(int j=0;j<=104;j++)
            {
                dp[i][j]=-1;
            }
        }
        
        return editDistanceDP(s,t,s.length(),t.length());
        
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends