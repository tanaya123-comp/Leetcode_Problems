class Solution {
public:
     int arr[201][201];
    int solve(vector<vector<int>>& matrix,int i,int j)
    {
        int l=0,r=0,u=0,d=0;
        if(arr[i][j]!=-1)
        {
            return arr[i][j];
        }
        
        if((i-1)>=0&&matrix[i-1][j]>matrix[i][j])
        {
            l=solve(matrix,i-1,j);
        }
        if((j-1)>=0&&matrix[i][j-1]>matrix[i][j])
        {
            r=solve(matrix,i,j-1);
        }
        if((i+1)<matrix.size()&&matrix[i+1][j]>matrix[i][j])
        {
            d=solve(matrix,i+1,j);
        }
        if((j+1)<matrix[0].size()&&matrix[i][j+1]>matrix[i][j])
        {
            u=solve(matrix,i,j+1);
        }
        return arr[i][j]=(1+max(max(l,r),max(u,d)));
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n,m,i,j;
        n=matrix.size();
        m=matrix[0].size();
        int ans=0;
        for(i=0;i<201;i++)
        {
            for(j=0;j<201;j++)
            {
                arr[i][j]=-1;
            }
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                ans=max(ans,solve(matrix,i,j));
            }
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<arr[i][j]<<" ";
                ans=max(ans,arr[i][j]);
            }
            cout<<"\n";
        }
        
        return ans;   
    }
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
        
//     }
};