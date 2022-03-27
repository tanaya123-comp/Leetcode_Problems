// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[205][205];
    
    int eggDropRec(int e,int f)
    {
        if(dp[e][f]!=-1)
            return dp[e][f];
            
        if(e==1)
            return dp[e][f]=f;
            
        if(f<=1)
            return dp[e][f]=f;
            
        int ans=INT_MAX;
        
        for(int k=1;k<=f;k++)
        {
            int temp=max(eggDropRec(e-1,k-1),eggDropRec(e,f-k));
            
            ans=min(ans,temp);
        }
        
        return dp[e][f]=ans+1;
    }
    
    int eggDrop(int n, int k) 
    {
        // your code here
        for(int i=0;i<=200;i++)
        {
            for(int j=0;j<=200;j++)
            {
                dp[i][j]=-1;
            }
        }
        
      return  eggDropRec(n,k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends