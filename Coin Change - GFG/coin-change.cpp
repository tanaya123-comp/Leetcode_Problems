// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  long long int dp[1001][1001];
  
  long long int countRec(int S[],int sum,int n)
  {
      if(sum==0)
      {
          return dp[sum][n]=1;
      }
      if(n==0)
      {
          return dp[sum][n]=0;
      }
      if(dp[sum][n]!=-1)
      {
          return dp[sum][n];
      }
      if(S[n-1]<=sum)
      {
          return dp[sum][n]=countRec(S,sum-S[n-1],n)+countRec(S,sum,n-1);
      }
      return dp[sum][n]=countRec(S,sum,n-1);
  }
  
    long long int count(int S[], int m, int n) {
        
        for(int i=0;i<=1000;i++)
        {
            for(int j=0;j<=1000;j++)
            {
                dp[i][j]=-1;
            }
        }
        
        return countRec(S,n,m);
        

        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends