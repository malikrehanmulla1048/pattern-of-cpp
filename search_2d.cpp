#include <vector>
#include <iostream>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int st = 0, end=matrix.size()-1 ;
     
    while(st<=end)
    {
        int mid = st+(end-st)/2;
        int st2 = 0;
        int end2= matrix[mid].size()-1;
        if(matrix[mid][st2]<=target &&  matrix[mid][end2]>= target )
        {
            while(st2<=end2)
            {
                int mid2 = st2+(end2-st2)/2;
                if(matrix[mid][mid2] == target) return true;
                if(matrix[mid][mid2]<target) st2 = mid2+1;
                else end2=mid2-1;
            }
            return false;
        }
        if(matrix[mid][st2] > target) end = mid-1;
        if(matrix[mid][end2] < target) st = mid+1;
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {{1}};
    int target = 2;
    bool result = searchMatrix(matrix, target);
    cout<<result;
    return 0;
}