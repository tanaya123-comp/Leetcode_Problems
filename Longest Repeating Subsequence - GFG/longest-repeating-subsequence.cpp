// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    
	   // int dp[1001][1001];
	    
	   // int lrsDP(string s1,string s2,int x,int y)
	   // {
	   //     if(x==0||y==0)
	   //     {
	   //         return dp[x][y]=0;
	   //     }
	   //     else if(s1[x-1]==s2[y-1]&&x!=y)
	   //     {
	   //         return dp[x][y]=lrsDP(s1,s2,x-1,y-1)+1;
	   //     }
	   //     else
	   //     {
	   //         return dp[x][y]=max(lrsDP(s1,s2,x-1,y),lrsDP(s1,s2,x,y-1));
	   //     }
	   // }
	
		int LongestRepeatingSubsequence(string str){
		    // Code here
		   int len=str.length();
		   int dp[len+1][len+1];
		   for(int i=0;i<=len;i++)
		   {
		       for(int j=0;j<=len;j++)
		       {
		           if(i==0||j==0)
		           {
		               dp[i][j]=0;
		           }
		           else if(str[i-1]==str[j-1]&&i!=j)
		           {
		               dp[i][j]=1+dp[i-1][j-1];
		           }
		           else
		           {
		               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		           }
		       }
		   }
		   
		    
		    return dp[len][len];
		    
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends