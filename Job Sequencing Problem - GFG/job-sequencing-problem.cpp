// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/


bool tocompare(Job a,Job b)
{
    return a.profit>b.profit;
}


class Solution 
{
    public:
    
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        
        sort(arr,arr+n,tocompare);
        
        int maxi=arr[0].dead;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i].dead);
        }
        
        vector<int> slot(maxi+1);
        int number_of_jobs=0;
        int max_profit=0;
        
        for(int i=0;i<maxi;i++)
        {
            slot[i]=false;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>=1;j--)
            {
                if(slot[j]==false)
                {
                    slot[j]=true;
                    number_of_jobs++;
                   // cout<<arr[i].id<<" ";
                    max_profit=max_profit+arr[i].profit;
                    break;
                }
            }
        }
        
        vector<int> ans;
        ans.push_back(number_of_jobs);
        ans.push_back(max_profit);
        return ans;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends