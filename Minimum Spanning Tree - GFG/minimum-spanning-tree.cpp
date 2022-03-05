// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V,INT_MAX);
        vector<int> MST(V,false);
        int i,j,k;
        int n=V;
        int sum=0;
        key[0]=0;
        i=0;
        while(i<n)
        {
            int index=-1;
            int minDist=INT_MAX;
            for(j=0;j<V;j++)
            {
                if(key[j]<minDist&&MST[j]==false)
                {
                    minDist=key[j];
                    index=j;
                    
                }
            }
            
            if(index==-1)
            {
                break;
            }
            else
            {
                MST[index]=true;
                sum=sum+minDist;
            }
            
            for(j=0;j<adj[index].size();j++)
            {
                if(MST[adj[index][j][0]]==false&&key[adj[index][j][0]]>adj[index][j][1])
                {
                    key[adj[index][j][0]]=adj[index][j][1];
                   // parent[adj[index][j][0]]=index;
                }
            }
            i++;
        }
       
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends