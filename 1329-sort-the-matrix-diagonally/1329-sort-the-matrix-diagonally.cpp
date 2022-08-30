class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n,m,i,j,k,t;
        n=mat.size();
        m=mat[0].size();
        
        for(i=0;i<n;i++)
        {
            vector<int> vec;
            j=i;
            k=0;
            while(j<n&&k<m)
            {
                vec.push_back(mat[j][k]);
                j++;
                k++;
            }
            sort(vec.begin(),vec.end());
            j=i;
            k=0;
            t=0;
            while(j<n&&k<m)
            {
                mat[j][k]=vec[t];
                j++;
                k++;
                t++;
            }
        }
        
        for(i=1;i<m;i++)
        {
            vector<int> vec;
            j=0;
            k=i;
            while(j<n&&k<m)
            {
                vec.push_back(mat[j][k]);
                j++;
                k++;
            }
            sort(vec.begin(),vec.end());
            j=0;
            k=i;
            t=0;
            while(j<n&&k<m)
            {
                mat[j][k]=vec[t];
                j++;
                k++;
                t++;
            }
        }
        return mat;
    }
};