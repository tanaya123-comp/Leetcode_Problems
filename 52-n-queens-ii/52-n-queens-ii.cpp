class Solution {
public:
    
    set<vector<vector<int>>> st;
    
    
    bool isSafe(vector<vector<int> > board,int r,int c,int n)
    {
        //check col
        for(int i=0;i<n;i++)
        {
            if(board[i][c]==1)
                return false;
        }
        
        //check upperdiagonal left
        for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]==1)
                return false;
        }
        
        //check upperdiagonal right
        for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++)
        {
            if(board[i][j]==1)
                return false;
        }
        
        return true;
    }
    
    
    void placeQueens(vector<vector<int> > board,int row,int n)
    {
        if(row==n)
        {
          //  cout<<"Here";
            st.insert(board);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,row,i,n))
            {
                board[row][i]=1;
                
                placeQueens(board,row+1,n);
                
                board[row][i]=0;
            }
        }
        
    }
    
    int totalNQueens(int n) {
        
        vector<vector<int> > board(n,vector<int> (n,0));
        
        placeQueens(board,0,n);
        
        return st.size();
        
    }
};