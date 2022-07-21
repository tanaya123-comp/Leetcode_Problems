class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        
        int n,i,j,k,r,x,y;
        n=circles.size();
        
        int vec[202][202]={0};
        
        for(i=0;i<=201;i++)
        {
            for(j=0;j<=201;j++)
            {
                for(k=0;k<n;k++)
                {
                    x=circles[k][0];
                    y=circles[k][1];
                    r=circles[k][2];
                    
                    if((x-i)*(x-i)+(y-j)*(y-j)<=r*r)
                    {
                        vec[i][j]++;
                    }
                }
            }
        }
        
        int ans=0;
        
        for(i=0;i<=201;i++)
        {
            for(j=0;j<=201;j++)
            {
                if(vec[i][j])
                {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};