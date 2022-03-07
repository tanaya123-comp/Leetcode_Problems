// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return k;
        }
        long long same[n+1];
        long long different[n+1];
        same[0]=0;
        different[0]=0;
        same[1]=k;
        different[1]=k;
        same[2]=k;
        different[2]=k*(k-1);
        for(int i=3;i<=n;i++)
        {
            same[i]=different[i-1]%1000000007;
            different[i]=(((same[i-1]+different[i-1])%1000000007)*(k-1))%1000000007;
        }
        return (same[n]+different[n])%1000000007;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends