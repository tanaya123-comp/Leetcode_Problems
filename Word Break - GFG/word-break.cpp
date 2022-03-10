// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_set<string> s1;
    
    int solve(string s)
    {
        if(s.length()==0)
        {
            return 1;
        }
        int n=s.length();
        for(int i=1;i<=n;i++)
        {
            if(s1.count(s.substr(0,i))!=0)
            {
                if(solve(s.substr(i))==1)
                {
                    return 1;
                }
            }
        }
        return 0;
    }

    int wordBreak(string A, vector<string> &B) {
        //code here
        for(auto x:B)
        {
            s1.insert(x);
        }
        return solve(A);
        
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends