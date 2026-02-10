#include <vector>
#include <iostream>

using namespace std;
    bool isSafe(vector<vector<char>>& board,int row,int col,char dig)
    {
        //horizontal
        for(int j=0;j<9;j++)
        {
            if(board[row][j] == dig) return false;
        }
        //vertical
        for(int j=0;j<9;j++)
        {
            if(board[j][col] == dig) return false;
        }
        //box
        for(int i = row/3*3;i<=row/3*3+2;i++)
        {
            for(int j = col/3*3;j<=col/3*3+2;j++)
            {
                if(board[i][j] == dig) return false;
            }
        }
        return true;
    }
bool solvesudok(vector<vector<char>>& board,int row,int col)
    {
    if(row == 9) return true;
    if(col == 9) return solvesudok(board, row + 1, 0);
    if(board[row][col] != '.')
    {
        return solvesudok(board,row,col+1);
    }
    for(char i ='1';i<='9';i++)
    {
        if(isSafe(board,row,col,i))
        {
            board[row][col] = i;
            if(solvesudok(board,row,col+1)) return true;
            board[row][col] = '.';
        }
   }
    return false;
}
void solveSudoku(vector<vector<char>>& board) {
    solvesudok(board,0,0);
}
int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solveSudoku(board);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}