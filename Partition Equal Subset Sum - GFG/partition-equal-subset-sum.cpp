// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // int DP[1001][1001];

    // int equalPartDP(int N,int arr[],int sum)
    // {
    //     if(sum==0)
    //     {
    //         return DP[N][sum]=1;
    //     }
    //     if(N==0)
    //     {
    //         return DP[N][sum]=0;
    //     }
    //     if(DP[N][sum]!=-1)
    //     {
    //         return DP[N][sum];
    //     }
    //     if(arr[N-1]<=sum)
    //     {
    //         return DP[N][sum]=equalPartDP(N-1,arr,sum-arr[N-1])||equalPartDP(N-1,arr,sum);
    //     }
    //     return DP[N][sum]=equalPartDP(N-1,arr,sum);
    // }

    int equalPartition(int N, int arr[])
    {
        // code here
        
        int sum=0;
        int i,j;
        for(i=0;i<N;i++)
        {
            sum=sum+arr[i];
        }
        if(sum%2!=0)
        {
            return 0;
        }
        // for(i=0;i<1001;i++)
        // {
        //     for(j=0;j<1001;j++)
        //     {
        //         DP[i][j]=-1;
        //     }
        // }
        sum=sum/2;
        bool dp[N+1][sum+1];
        for(i=0;i<=N;i++)
        {
            for(j=0;j<=sum;j++)
            {
                if(j==0)
                {
                    dp[i][j]=true;
                }
                else if(i==0)
                {
                    dp[i][j]=false;
                }
                else if(arr[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[N][sum];
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends