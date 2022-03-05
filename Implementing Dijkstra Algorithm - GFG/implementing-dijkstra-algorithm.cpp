// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        int i,j;
        vector<int> dist(V,INT_MAX);
        
        priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;
        dist[S]=0;
        
        pq.push(make_pair(0,S));
        
        while(!pq.empty())
        {
            pair<int,int> p=pq.top();
            pq.pop();
            
            int distance=p.first;
            
            int source=p.second;
            for(i=0;i<adj[source].size();i++)
            {
                if(distance+adj[source][i][1]<dist[adj[source][i][0]])
                {
                    dist[adj[source][i][0]]=distance+adj[source][i][1];
                    pq.push(make_pair(dist[adj[source][i][0]],adj[source][i][0]));
                }
            }
        }
        
        return dist;
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends