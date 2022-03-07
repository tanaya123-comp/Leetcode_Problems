// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r)
    {
        long long int dp[n+1][r+1];
        if(n<r)
        {
            return 0;
        }
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=min(n,r);j++)
            {
                if(j==0||j==i)
                {
                    dp[i][j]=1;
                }
                else
                {
                    dp[i][j]=(dp[i-1][j-1]%(1000000007)+dp[i-1][j]%(1000000007))%(1000000007);
                }
            }
        }
        return dp[n][r]%(1000000007);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends