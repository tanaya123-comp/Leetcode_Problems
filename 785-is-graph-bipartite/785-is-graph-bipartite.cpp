class Solution {
public:
    
    bool isBipartiteBFS(vector<vector<int> > graph,int index,vector<int> &color)
    {
        int i,j;
        queue<int> q;
        color[index]=0;
        q.push(index);
        while(!q.empty())
        {
            i=q.front();
            q.pop();
            for(j=0;j<graph[i].size();j++)
            {
                if(color[graph[i][j]]==-1)
                {
                    color[graph[i][j]]=1-color[i];
                    q.push(graph[i][j]);
                }
                else if(color[graph[i][j]]==color[i])
                {
                    return false;
                }
            }
        }
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n,i;
        n=graph.size();
        vector<int> color(n,-1);
        for(i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                 if(!isBipartiteBFS(graph,i,color))
                 {
                     return false;
                 }
            }
        }
        return true;
        
    }
};