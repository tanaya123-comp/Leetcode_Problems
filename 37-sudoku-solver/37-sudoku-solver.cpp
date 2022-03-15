class Solution {
public:
    
    bool isValid(vector<vector<char> > &board,int row,int col,char ch)
    {
        
        //check for column
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==ch)
                return false;
        }

        //check for row
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==ch)
                return false;
        }
        
        //check for each box;
        int x0=(row/3)*3;
        int y0=(col/3)*3;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[x0+i][y0+j]==ch)
                    return false;
            }
        }
        
        return true;
    }
    
    
    bool helper(vector<vector<char>> &board,int row,int col)
    {
        if(row==9)
            return true;
        
        if(col==9)
            return helper(board,row+1,0);
        
        if(board[row][col]!='.')
            return helper(board,row,col+1);
        
        for(char ch='1';ch<='9';ch++)
        {
            if(isValid(board,row,col,ch))
            {
                board[row][col]=ch;
                
                if(helper(board,row,col+1))
                    return true;
                
                board[row][col]='.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) 
    {
        bool result=helper(board,0,0);
    }
};