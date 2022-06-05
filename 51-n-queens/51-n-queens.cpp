class Solution {
public:
    
    vector<vector<string> > allSolutions;
    
   bool isSafe(vector<string> board,int row,int col)
    {
        //check if we can place in this column or not
        for(int i=row;i>=0;i--)
        {
            if(board[i][col]=='Q')
            {
                return false;
            }
        }
        
        //check upper left diagonal
        for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        
        //check upper right diagonal
        for(int i=row,j=col;i>=0&&j<board.size();i--,j++)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        
        return true;
    }
    
    void placeQ(vector<string> board,int r,int n)
    {
        if(r==n)
        {
            allSolutions.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,r,i))
            {
                board[r][i]='Q';
                placeQ(board,r+1,n);
                board[r][i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        
        vector<string> board(n,string(n,'.'));
        
        placeQ(board,0,n);
        
        return allSolutions;
        
    }
};