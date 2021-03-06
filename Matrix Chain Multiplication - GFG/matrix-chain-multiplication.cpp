// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[105][105];
    
    int MCM(int arr[],int i,int j)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        if(i==j)
            return dp[i][j]=0;
            
        int ans=INT_MAX;
        int temp;
        for(int k=i;k<j;k++)
        {
            temp=MCM(arr,i,k)+MCM(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            
            if(temp<ans)
                ans=temp;
        }
        
        return dp[i][j]=ans;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=N;j++)
            {
                dp[i][j]=-1;
            }
        }
        
        for(int i=0;i<=N;i++)
        {
            dp[i][i]=0;
        }
        
        for(int k=2;k<=N;k++)
        {
            for(int i=1;i<=N-k;i++)
            {
                int j=i+k-1;
                int ans=INT_MAX;
                int temp;
                for(int t=i;t<j;t++)
                {
                    temp=dp[i][t]+dp[t+1][j]+arr[i-1]*arr[t]*arr[j];
                    ans=min(ans,temp);
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