class NumMatrix {
public:
    
    vector<vector<int> > dp2;
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        int n,m,i,j;
        n=matrix.size();
        m=matrix[0].size();
        
        vector<vector<int> > dp(n,vector<int> (m,0));
        
        dp[0][0]=matrix[0][0];
        for(i=1;i<m;i++)
        {
            dp[0][i]=matrix[0][i]+dp[0][i-1];
        }
        
        for(i=1;i<n;i++)
        {
            dp[i][0]=matrix[i][0]+dp[i-1][0];
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i>0&&j>0)
                {
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1]+matrix[i][j])-dp[i-1][j-1];
                }
            }
        }
        
        dp2=dp;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        
        // for(int i=0;i<dp2.size();i++)
        // {
        //     for(int j=0;j<dp2[0].size();j++)
        //     {
        //         cout<<dp2[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        if(row1==0&&col1==0)
        {
            return dp2[row2][col2];
        }
        
        if(row1>0&&col1==0)
        {
            return dp2[row2][col2]-dp2[row1-1][col2];
        }
        
        if(row1==0&&col1>0)
        {
            return dp2[row2][col2]-dp2[row2][col1-1];
        }
        
        return dp2[row2][col2]-(dp2[row1-1][col2]+dp2[row2][col1-1]-dp2[row1-1][col1-1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */