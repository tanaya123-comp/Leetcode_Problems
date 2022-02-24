// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int ans=0;
        int i,j,k;
        multimap<int,int> mp;
        multimap<int,int>::iterator it;
        int sum=0;
        for(i=0;i<n;i++)
        {
            sum=sum+A[i];
            if(sum==0)
            {
                ans=max(ans,i+1);
            }
            if(mp.find(sum)!=mp.end())
            {
                it=mp.find(sum);
                ans=max(ans,i-(it->second));
            }
            else {
                mp.insert({sum,i});
            }
        }
        return ans;   
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends