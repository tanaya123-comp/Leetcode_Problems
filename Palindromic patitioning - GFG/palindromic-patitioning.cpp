// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1000][1000];
    
   bool isPallindrome(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    int palindromicPartition(string str)
    {
        int n=str.length();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=-1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=0;
        }
        
        for(int k=2;k<=n;k++)
        {
            for(int i=0;i<=n-k;i++)
            {
                int j=i+k-1;
                if(isPallindrome(str,i,j))
                {
                    dp[i][j]=0;
                    continue;
                }
                int ans=INT_MAX;
                for(int t=i;t<j;t++)
                {
                    ans=min(ans,dp[i][t]+dp[t+1][j]+1);
                }
                dp[i][j]=ans;
            }
        }
        
        return dp[0][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends