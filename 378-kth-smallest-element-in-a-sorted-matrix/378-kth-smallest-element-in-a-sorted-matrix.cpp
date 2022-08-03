class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n,i,j,t;
        n=matrix.size();
        
        int ans=0;
        int low,mid,high;
        
        low=matrix[0][0];
        high=matrix[n-1][n-1];
        
        while(low<high)
        {
            mid=(low)+((high-low)/2);
            
            ans=0;
           
            for(i=0;i<n;i++)
            {
                j=(upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
                ans=ans+j;
            }
            
            if(ans<k)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
           
        }
        return low;
    }
};