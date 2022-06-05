class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int n,m,i,j;
        n=matrix.size();
        m=matrix[0].size();
        
        vector<vector<int> > transpose(m,vector<int> (n,0));
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                transpose[j][i]=matrix[i][j];
            }
        }
        return transpose;
    }
};