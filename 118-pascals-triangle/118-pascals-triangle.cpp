class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int> > vec;
        vector<int> a;
        a.push_back(1);
        vec.push_back(a);
        int i,j;
        for(i=2;i<=numRows;i++)
        {
            vector<int> b;
            b.push_back(1);
            for(j=1;j<=i-2;j++)
            {
                b.push_back(vec[i-2][j-1]+vec[i-2][j]);
            }
            b.push_back(1);
            vec.push_back(b);
        }
        return vec;
        
        
    }
};