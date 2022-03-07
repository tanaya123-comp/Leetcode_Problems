// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int i,j;
        for(i=1;i<m;i++) //cols
        {
            for(j=0;j<n;j++)    //rows
            {
                int x,y,z;
                if((j-1)>=0&&(i-1)>=0)
                {
                    x=M[j-1][i-1];
                }
                else
                {
                    x=INT_MIN;
                }
                if((i-1)>=0)
                {
                    y=M[j][i-1];
                }
                else
                {
                    y=INT_MIN;
                }
                if((i-1)>=0&&(j+1)<n)
                {
                    z=M[j+1][i-1];
                }
                else
                {
                    z=INT_MIN;
                }
                //cout<<x<<" "<<y<<" "<<z<<"\n";
                 M[j][i]=M[j][i]+max(x,max(y,z));
               // cout<<M[j][i]<<" ";
            }
            //cout<<"\n";
        }
        
        int ans=M[0][m-1];
        for(i=0;i<n;i++)
        {
            ans=max(ans,M[i][m-1]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends