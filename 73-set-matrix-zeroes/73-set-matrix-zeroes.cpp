class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row,col,i,j;
        row=matrix.size();
        col=matrix[0].size();
        unordered_set<int> r,c;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    cout<<i<<" "<<j<<"\n";
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if((r.count(i)!=0)||(c.count(j)!=0))
                {
                  //  cout<<i<<" "<<j<<"\n";
                    matrix[i][j]=0;
                }
            }
        }
        
        
    }
};