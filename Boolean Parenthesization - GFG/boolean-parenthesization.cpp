// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   


int dp[2][201][201];

int mod = 1003;
int solve(string s,int i,int j,bool isTrue)
{
   if(i>j)
   return 0;
   if(i == j)
   {
       if(isTrue == true)
       {
           if(s[i] == 'T')
           return 1;
           else
           return 0;
       }
       else
       {
           if(s[i] == 'F')
           return 1;
           else
           return 0;
       }
       
   }
   if(dp[isTrue][i][j] > -1)
   return dp[isTrue][i][j];
   
   int ans = 0;
   for(int k=i+1; k<j; k+=2)
   {
       int lt = solve(s,i,k-1,true);
       int lf = solve(s,i,k-1,false);

       int rt = solve(s,k+1,j,true);
       int rf = solve(s,k+1,j,false);

       if(s[k] == '&')
       {
           if(isTrue == true)
           ans = ((ans % mod) + (lt*rt)%mod) % mod;
           else
           ans = ((ans % mod) + (lt*rf)% mod + (lf * rt)% mod + (lf * rf))% mod;
       }
       else if(s[k] == '|')
       {
           if(isTrue == true)
            ans = ((ans % mod) + (lt*rt)% mod + (lf*rt)% mod + (lt *rf))% mod;
           else
            ans = ((ans % mod) + (lf*rf));
       }
       else
       {
           if(isTrue == true)
           ans = ((ans % mod) + (lt*rf)% mod + (lf*rt))% mod;
           else
            ans = ((ans % mod) + (lt*rt)% mod + (lf*rf))% mod;
       }
   }
    dp[isTrue][i][j] = ans % mod;
       return ans;
}
int countWays(int N, string S)
{
   memset(dp,-1,sizeof(dp));
   return solve(S,0,N-1,true);
}
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends