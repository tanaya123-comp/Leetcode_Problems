class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n=points.size();
        int i,j,connected,res;
        i=0;
        vector<bool> visited(n,false);
        connected=0;
        res=0;
        priority_queue<pair<int,int> > pq;
        while(++connected<n)
        {
            visited[i]=true;
            for(j=0;j<n;j++)
            {
                if(visited[j]==false)
                {
                    pq.push({-(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])),j});
                }
            }
            
            while(!pq.empty()&&visited[pq.top().second])
            {
                pq.pop();
            }
            res=res-pq.top().first;
            i=pq.top().second;
            pq.pop();
        }
        return res;
    }
};