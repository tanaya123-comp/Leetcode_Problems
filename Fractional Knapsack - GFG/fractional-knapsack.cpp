// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    bool static toCompare(Item a,Item b)
    {
        double first=(double)(a.value)/(double)(a.weight);
        double second=(double)(b.value)/(double)(b.weight);
        return first>second;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,toCompare);
        double Weight=0;
        double Value=0;
        for(int i=0;i<n;i++)
        {
            if(Weight+arr[i].weight<=W)
            {
                Weight+=arr[i].weight;
                Value+=arr[i].value;
               // W=W-arr[i].weight;
            }
            else
            {
           //     cout<<W<<"\n";
                int remain=W-Weight;
                Weight=Weight+(remain);
                Value=Value+(((double)(arr[i].value)/(double)arr[i].weight)*remain);
                
            }
        }
        return Value;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends