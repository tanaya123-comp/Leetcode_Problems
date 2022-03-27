// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
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
    int dp[1000][1000];
    int solve(string s,int i,int j)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(isPallindrome(s,i,j))
        {
            return dp[i][j]=0;
        }
        
        int ans=INT_MAX;
        
        for(int k=i;k<=j;k++)
        {
            if(isPallindrome(s,i,k))
            {
                ans=min(ans,1+solve(s,k+1,j));
            }
        }
        return dp[i][j]=ans;
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
        int ans=solve(str,0,n-1);
        return ans;
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