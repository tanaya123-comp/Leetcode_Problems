class Solution {
public:
    
    vector<vector<string> > numberOfWays;
    
    //check if we can place in this row or not
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
    
    void dfs(vector<string> &board,int row,int n)
    {
        if(row>=n)
        {
            numberOfWays.push_back(board);
            return;
        }
        
        //place in one-one column
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,row,i))
            {
                board[row][i]='Q';
                
                dfs(board,row+1,n);
                
                board[row][i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        if(n<=0)
        {
            return numberOfWays;
        }
        vector<string> board(n,string(n,'.'));
        
        dfs(board,0,n);
    
        return numberOfWays;
    }
};