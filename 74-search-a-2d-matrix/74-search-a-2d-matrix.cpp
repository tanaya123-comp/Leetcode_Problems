class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row,col;
        row=matrix.size();
        col=matrix[0].size();
        int i;
        int low,mid,high;
        low=0;
        high=row-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            //cout<<mid<<"\n";
            if(matrix[mid][0]==target)
            {
                return true;
            }
            else if(matrix[mid][0]>target)
            {
                high=mid-1;
            }
            else if(matrix[mid][0]<=target)
            {
                if(matrix[mid][col-1]==target)
                {
                    return true;
                }
                else if(matrix[mid][col-1]<target)
                {
                    low=mid+1;
                }
                else
                {
                  //  cout<<"here"<<low<<"\n";
                    break;
                }
            }
        }
        if(low>high)
        {
            return false;
        }
     //   cout<<low<<"\n";
        i=mid;
        low=0;
        high=col-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(matrix[i][mid]==target)
            {
                return true;
            }
            else if(matrix[i][mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return false;
        
    }
};