// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int i,j;
	    vector<int> dp(n,1);
	    vector<int> sum(n,0);
	    for(i=0;i<n;i++)
	    {
	        sum[i]=arr[i];
	    }
	    int ans=arr[0];
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<i;j++)
	        {
	            if(arr[i]>arr[j]&&sum[i]<sum[j]+arr[i])
	            {
	                dp[i]=dp[j]+1;
	                sum[i]=sum[j]+arr[i];
	                ans=max(ans,sum[i]);
	            }
	        }
	    }
	    return ans;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends