class Solution {
public:
    
    bool dfs(int index,vector<int> adj[],vector<bool> &visited,vector<bool> visitedDFS)
    {
        visited[index]=true;
        visitedDFS[index]=true;
        for(int i=0;i<adj[index].size();i++)
        {
            if(visited[adj[index][i]]==false)
            {
               if(dfs(adj[index][i],adj,visited,visitedDFS))
               {
                   return true;
               }
            }
            else if(visitedDFS[adj[index][i]]==true) {
                return true;
            }
        }
        visitedDFS[index]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> adj[numCourses];
        vector<bool> visited(numCourses,false);
        vector<bool> visitedDFS(numCourses,false);
        int i,j;
        for(i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(i=0;i<numCourses;i++)
        {
            if(visited[i]==false)
            {
                if(dfs(i,adj,visited,visitedDFS))
                {
                    return false;
                }
            }
        }
        return true;
    }
};