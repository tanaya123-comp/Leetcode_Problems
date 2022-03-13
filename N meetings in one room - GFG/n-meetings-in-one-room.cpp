// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
   static bool toCompare(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.first<p2.first)
        {
            return true;
        }
        else if(p2.first<p1.first)
        {
            return false;
        }
        if(p1.second<p2.second)
        {
            return true;
        }
        return false;
    }
    
    
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        int i,j,k;
        vector<pair<int,int> > vec;
        for(i=0;i<n;i++)
        {
            vec.push_back({end[i],start[i]});
        }
        sort(vec.begin(),vec.end(),toCompare);
        
        int end_time_prev=-1;
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(vec[i].second>end_time_prev)
            {
                end_time_prev=vec[i].first;
                ans++;
            }
        }
        return ans++;
    }
};

// bool compare(pair<int,int> p1,pair<int,int> p2)
//     {
//         if(p1.second<p2.second)
//         {
//             return true;
//         }
//         else if(p2.second<p1.second)
//         {
//             return false;
//         }
//         if(p1.first<p2.first)
//         {
//             return true;
//         }
//         return false;
//     }

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends