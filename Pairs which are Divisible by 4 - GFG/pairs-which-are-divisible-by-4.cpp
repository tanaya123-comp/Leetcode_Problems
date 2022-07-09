// { Driver Code Starts
// C++ Program to count pairs whose sum divisible
// by '4'
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int count4Divisibiles(int arr[], int n)
    {
        // Complete the function
       int freq[4] = {0, 0, 0, 0};
  
    // Count occurrences of all remainders
    for (int i = 0; i < n; i++)
        ++freq[arr[i] % 4];
  
    // If both pairs are divisible by '4'
    int ans = freq[0] * (freq[0] - 1) / 2;
  
    // If both pairs are 2 modulo 4
    ans += freq[2] * (freq[2] - 1) / 2;
  
    // If one of them is equal
    // to 1 modulo 4 and the
    // other is equal to 3 
    // modulo 4
    ans += freq[1] * freq[3];
  
    return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
         cin>>arr[i];
        Solution ob;
        cout << ob.count4Divisibiles(arr, n)<<endl;
    }
 
    return 0;
}  // } Driver Code Ends