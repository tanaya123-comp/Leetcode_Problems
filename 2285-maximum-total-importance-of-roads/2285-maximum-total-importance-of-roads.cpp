class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        int i,j,k,m;
        vector<int> indegree(n,0);
        vector<int> weight(n);
        m=roads.size();
        
        for(i=0;i<m;i++)
        {
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;
        }
        
        int x=n;
        
        priority_queue<pair<int,int> > pq;
        
        for(i=0;i<n;i++)
        {
            pq.push({indegree[i],i});
        }
        
        while(!pq.empty())
        {
            i=pq.top().second;
            j=pq.top().first;
            pq.pop();
            
            weight[i]=x;
            x--;
        }
        
        long long max_total_importance=0;
        for(i=0;i<m;i++)
        {
            j=roads[i][0];
            k=roads[i][1];
            
            max_total_importance+=weight[j]+weight[k];
        }
        
        return max_total_importance;
        
    }
};