class Solution {
public:
    
    bool isBipartiteDFS(vector<vector<int>>& graph,int index,vector<int> &color)
    {
        for(int i=0;i<graph[index].size();i++)
        {
            int neighbor=graph[index][i];
            if(color[neighbor]==-1)
            {
                color[neighbor]=1-color[index];
                 if(!isBipartiteDFS(graph,neighbor,color))
                {
                    return false;
                }
            }
            else if(color[neighbor]==color[index])
            {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n,i,j;
        n=graph.size();
        vector<int> color(n,-1);
        for(i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(!isBipartiteDFS(graph,i,color))
                {
                    return false;
                }
            }
        }
        return true;
    }
};