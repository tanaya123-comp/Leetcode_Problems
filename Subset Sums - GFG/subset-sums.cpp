// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    
    void getSubsetSum(vector<int> arr,int N,int sum,vector<int> &subset_sums)
    {
        if(N==0)
        {
            subset_sums.push_back(sum);
            return;
        }
        
        getSubsetSum(arr,N-1,sum+arr[N-1],subset_sums);
        
        getSubsetSum(arr,N-1,sum,subset_sums);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> subset_sums;
        
        getSubsetSum(arr,N,0,subset_sums);
        
        sort(subset_sums.begin(),subset_sums.end());
        
        return subset_sums;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends