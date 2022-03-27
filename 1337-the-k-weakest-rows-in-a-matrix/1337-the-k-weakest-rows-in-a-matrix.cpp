 bool toCompare(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.first<p2.first)
            return true;
        else if(p2.first<p1.first)
            return false;
        else if(p1.second<p2.second)
            return true;
        else 
            return false;
    }
    

class Solution {
public:
    
   
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int n,m,i,j,soldiers;
        n=mat.size();
        m=mat[0].size();
        vector<pair<int,int> > vec;
        for(i=0;i<n;i++)
        {
            soldiers=0;
            for(j=0;j<m;j++)
            {
                if(mat[i][j])
                    soldiers++;
            }
            vec.push_back(make_pair(soldiers,i));
        }
        sort(vec.begin(),vec.end(),toCompare);
        vector<int> rows;
        for(i=0;i<k;i++)
            rows.push_back(vec[i].second);
        return rows;
    }
};