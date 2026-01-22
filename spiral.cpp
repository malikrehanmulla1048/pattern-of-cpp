#include <vector>
#include <iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int srow = 0,scol = 0;
    int erow = m-1 ,ecol = n-1;
    int total = m*n;
    vector<int> update={};
    while(total>0)
    {
        for(int j = scol ; j<=ecol ;j++)
       {
            update.push_back(matrix[srow][j]);
            total--;
            if(total==0) return update;
        }
        for(int i = srow+1;i<=erow;i++)
        {
            update.push_back(matrix[i][ecol]);
            total--;
            if(total==0) return update;
        }
        for(int j = ecol-1 ; j>=scol;j--) 
        {
            update.push_back(matrix[erow][j]);
            total--;
            if(total==0) return update;
        }
        for(int i = erow-1 ; i>=srow+1;i--) 
        {
            update.push_back(matrix[i][scol]);
            total--;
            if(total==0) return update;     
        }
        srow++,scol++,erow--,ecol--;
   }
    return update;
}
int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans = spiralOrder( matrix);
    for(auto i : ans)
    {
        cout<< i << " ";
    }
    cout<< endl; 
    return 0;
}