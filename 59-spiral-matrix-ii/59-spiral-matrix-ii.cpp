class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        int i,j,k;
        vector<vector<int> > spiral(n,vector<int> (n));
        int r1,r2,c1,c2;
        r1=0;
        r2=n-1;
        c1=0;
        c2=n-1;
        k=1;
        while(r1<=r2&&c1<=c2)
        {
            for(i=c1;i<=c2;i++)
            {
                spiral[r1][i]=k;
                k++;
            }
            r1++;
            for(i=r1;i<=r2;i++)
            {
                spiral[i][c2]=k;
                k++;
            }
            c2--;
            if(r1>r2||c1>c2)
            {
                break;
            }
            for(i=c2;i>=c1;i--)
            {
                spiral[r2][i]=k;
                k++;
            }
            r2--;
            for(i=r2;i>=r1;i--)
            {
                spiral[i][c1]=k;
                k++;
            }
            c1++;
        }
        return spiral;
    }
};