class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n,m,low,mid,high,flag;
        n=matrix.size();
        m=matrix[0].size();
        low=0;
        high=n-1;
        flag=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(matrix[mid][0]<=target&&matrix[mid][m-1]>=target)
            {
                flag=1;
                break;
            }
            else if(matrix[mid][m-1]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(flag==0)
        {
            return false;
        }
        
        low=0;
        high=m-1;
        int r=mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(matrix[r][mid]==target)
                return true;
            if(matrix[r][mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        
        return false;
    }
};