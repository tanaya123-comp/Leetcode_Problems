class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
       int n,i,j,k;
        sort(points.begin(),points.end());
        n=points.size();
        vector<vector<int> > vec;
        int mini;
        j=-1;
        for(i=0;i<n;i++)
        {
            if(vec.size()==0)
            {
                vec.push_back(points[i]);
                mini=points[i][1];
                j++;
            }
            else if(points[i][0]<=vec[j][1]&&mini>=points[i][0])
            {
                vec[j][1]=points[i][1];
                mini=min(mini,points[i][1]);
            }
            else
            {
                vec.push_back(points[i]);
                mini=points[i][1];
                j++;
            }
        }
        
        return vec.size();
        
        
    }
};