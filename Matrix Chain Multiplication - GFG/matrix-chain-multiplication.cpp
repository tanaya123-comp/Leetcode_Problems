// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   

    int matrixMultiplication(int N, int arr[])
    {
        int dp[N+1][N+1];
        for(int i=0;i<=N;i++)
        {
            dp[i][i]=0;
        }
        int ans;
        for(int k=2;k<N;k++)
        {
            for(int i=1;i<=N-k;i++)
            {
                int j=i+k-1;
                ans=INT_MAX;
                for(int t=i;t<j;t++)
                {
                    ans=min(ans,dp[i][t]+dp[t+1][j]+arr[i-1]*arr[t]*arr[j]);
                }
                dp[i][j]=ans;
            }
            
        }
        return dp[1][N-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends