// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
       vector<int> bfs;
        queue<int> st;
        vector<bool> visited(V,false);
        
        st.push(0);
        visited[0]=true;
        bfs.push_back(0);
        while(!st.empty())
        {
            int i=st.front();
            st.pop();
            for(int j=0;j<adj[i].size();j++)
            {
                if(visited[adj[i][j]]==false)
                {
                    st.push(adj[i][j]);
                    visited[adj[i][j]]=true;
                    bfs.push_back(adj[i][j]);
                }
            }
        }
        return bfs;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends