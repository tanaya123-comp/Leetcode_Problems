// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfsOfGraphRec(vector<bool> &visited,vector<int> adj[],int index,vector<int> &dfs)
    {
           visited[index]=true;
           dfs.push_back(index);
           
           for(int i=0;i<adj[index].size();i++)
           {
               if(visited[adj[index][i]]==false)
               {
                   dfsOfGraphRec(visited,adj,adj[index][i],dfs);
               }
           }
            
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {

        vector<int> dfs;
        vector<bool> visited(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                
                dfsOfGraphRec(visited,adj,i,dfs);
            }
        }
        return dfs;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends