// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i,j,t,kthSmallest;
        i=0;
        j=0;
        t=0;
        while(i<n&&j<m)
        {
            if(arr1[i]<=arr2[j])
            {
                kthSmallest=arr1[i];
                i++;
            }
            else 
            {
                kthSmallest=arr2[j];
                j++;
            }
            t++;
            if(t==k)
                return kthSmallest;
        }
        while(i<n)
        {
            kthSmallest=arr1[i];
            i++;
            t++;
            if(t==k)
                return kthSmallest;
        }
        while(j<m)
        {
            kthSmallest=arr2[j];
            j++;
             t++;
            if(t==k)
                return kthSmallest;
        }
        return -1;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends