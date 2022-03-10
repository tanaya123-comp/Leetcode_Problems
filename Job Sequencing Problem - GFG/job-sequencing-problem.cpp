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

bool comparison(Job a, Job b)
{
     return (a.profit > b.profit);
}

class Solution 
{
    public:
    
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
      sort(arr, arr+n, comparison);
      vector<int> jobs;

        int result[n]; // To store result (Sequence of jobs)
        bool slot[n];  // To keep track of free time slots
    
        // Initialize all slots to be free
        for (int i=0; i<n; i++)
            slot[i] = false;
    
        // Iterate through all given jobs
        for (int i=0; i<n; i++)
        {
           // Find a free slot for this job (Note that we start
           // from the last possible slot)
           for (int j=min(n, arr[i].dead)-1; j>=0; j--)
           {
              // Free slot found
              if (slot[j]==false)
              {
                 result[j] = i;  // Add this job to result
                 slot[j] = true; // Make this slot occupied
                 break;
              }
           }
        }
        
        int num_of_jobs=0;
        int max_profit=0;
        for(int i=0;i<n;i++)
        {
            if(slot[i])
            {
                num_of_jobs++;
                max_profit=max_profit+arr[result[i]].profit;
            }
        }
        jobs.push_back(num_of_jobs);
        jobs.push_back(max_profit);
        return jobs;
    
    
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