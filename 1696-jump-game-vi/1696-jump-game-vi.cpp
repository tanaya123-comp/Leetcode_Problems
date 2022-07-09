class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int siz,i,j,t;
        siz=nums.size();
        
        vector<int> dp(siz);
        
        dp[0]=nums[0];
        
        priority_queue<pair<int,int> > pq;
        
        pq.push(make_pair(dp[0],0));
        
        for(i=1;i<siz;i++)
        {
            while(!pq.empty()&&pq.top().second<i-k)
            {
                pq.pop();
            }
            dp[i]=nums[i]+pq.top().first;
            pq.push(make_pair(dp[i],i));
        }
        
        return dp[siz-1];
        
    }
};