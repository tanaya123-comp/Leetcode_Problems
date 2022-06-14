class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int i,j,n;
        n=triangle.size();
        
        for(i=1;i<n;i++)
        {
            for(j=0;j<triangle[i].size();j++)
            {
                int x=INT_MAX;
                int y=INT_MAX;
                if((j-1)>=0)
                {
                    x=triangle[i-1][j-1];
                }
                if((j)<triangle[i-1].size())
                {
                    y=triangle[i-1][j];
                }
                triangle[i][j]=triangle[i][j]+min(x,y);
              //  cout<<triangle[i][j]<<" ";
           }
            //cout<<"\n";
        }
        int ans=INT_MAX;
        for(i=0;i<n;i++)
        {
            ans=min(ans,triangle[n-1][i]);
        }
        return ans;
    }
};