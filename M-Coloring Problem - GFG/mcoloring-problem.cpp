// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(int node,bool graph[101][101],vector<int> color,int c,int V)
{
    for(int i=0;i<V;i++)
    {
        if(graph[node][i]==true)
        {
            if(i!=node)
            {
                if(color[i]==c)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool isPossible(int node,bool graph[101][101],int m,int V,vector<int> color)
{
    if(node==V)
        return true;
        
    for(int i=1;i<=m;i++)
    {
        if(isSafe(node,graph,color,i,V))
        {
            color[node]=i;
            
            if(isPossible(node+1,graph,m,V,color))
                return true;
                
            color[node]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int> color(V,0);
    if(isPossible(0,graph,m,V,color))
        return true;
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends