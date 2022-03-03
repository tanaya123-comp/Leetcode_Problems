class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> indegree(numCourses,0);
        vector<int> adj[numCourses];
        queue<int> q;
        int count=0;
        int i,j,n;
        n=prerequisites.size();
        for(i=0;i<n;i++)
        {
            indegree[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            i=q.front();
            q.pop();
            for(j=0;j<adj[i].size();j++)
            {
                indegree[adj[i][j]]--;
                if(indegree[adj[i][j]]==0)
                {
                    q.push(adj[i][j]);
                }
            }
            count++;
        }
        if(count==numCourses)
        {
            return true;
        }
        return false;
        
    }
};