bool toCompare(vector<int> a,vector<int> b)
    {
        if(a[0]<b[0])
        {
            return true;
        }
        else if(a[0]>b[0])
        {
            return false;
        }
        if(a[1]<b[1])
        {
            return true;
        }
        return false;
    }

class Solution {
public:
    
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n,i,j;
        n=intervals.size();
        sort(intervals.begin(),intervals.end(),toCompare);
        vector<vector<int> > ans;
        j=0;
        for(i=0;i<n;i++)
        {
            if(ans.size()==0)
            {
                ans.push_back(intervals[i]);
            }
            else if(ans[j][1]>=intervals[i][0])
            {
                ans[j][0]=min(ans[j][0],intervals[i][0]);
                ans[j][1]=max(ans[j][1],intervals[i][1]);
            }
            else
            {
                 ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
    }
};