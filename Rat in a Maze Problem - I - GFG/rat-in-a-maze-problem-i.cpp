// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector<string> paths;
    
    void helper(string s,int n,vector<vector<int> > &m,int i,int j)
    {
        if(i==n-1&&j==n-1)
        {
            paths.push_back(s);
            return;
        }
        
        m[i][j]=0;
        
        if((i-1)>=0&&m[i-1][j]==1)
        {
            helper(s+"U",n,m,i-1,j);
        }
        if((i+1)<n&&m[i+1][j]==1)
        {
            helper(s+'D',n,m,i+1,j);
        }
        if((j-1)>=0&&m[i][j-1]==1)
        {
            helper(s+'L',n,m,i,j-1);
        }
        if((j+1)<n&&m[i][j+1]==1)
        {
            helper(s+'R',n,m,i,j+1);
        }
        
        m[i][j]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s="";
        
        if(m[0][0]==0)
            return paths;
        
        helper(s,n,m,0,0);
        
        return paths;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends