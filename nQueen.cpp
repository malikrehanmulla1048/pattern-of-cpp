#include<iostream>
#include<vector>
#include<string>
 using namespace std;

    bool isSafe(vector<string> &board,int row,int i,int n)
    {
        //1 horizontal
        for(int j=0;j<n;j++)
        {
            if(board[j][i]=='Q') return false;
        }
        //vertical
        for(int j=0;j<n;j++)
        {
            if(board[row][j]=='Q') return false;
        }
        //left up
        for(int row2 = row,i2  = i;row2>=0&&i2>=0;row2--,i2--)
        {
            if(board[row2][i2]=='Q') return false;
        }
        //right down
        for(int row2 = row,i2  = i;row2<n&&i2<n;row2++,i2++)
        {
            if(board[row2][i2]=='Q') return false;
        }
        //left down
        for(int row2 = row,i2  = i;row2<n&&i2>=0;row2++,i2--)
        {
            if(board[row2][i2]=='Q') return false;
        }
        //right up
        for(int row2 = row,i2  = i;row2>=0&&i2<n;row2--,i2++)
        {
            if(board[row2][i2]=='Q') return false;
        }
        return true;
    }
    void nQueen(vector<string> &board,vector<vector<string>> &ans,int row,int n)
    {
        if(row == n)
        {
            ans.push_back({board});
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,row,i,n))
            {
                board[row][i] = 'Q';
                nQueen(board,ans,row+1,n);
                board[row][i] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        nQueen(board,ans,0,n);
        return ans;
    }
int main()
{
    int n;
    cin>>n;
    vector<vector<string>> ans = solveNQueens(n);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
}