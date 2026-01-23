#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    vector<int> ans;
    unordered_map<int, int> m;
    int n = grid.size();
    for(int i =0;i<n;i++)
    {
        for(int j= 0;j<n;j++)
        {
            if(m.find(grid[i][j])!= m.end()) 
            {
                ans.push_back(grid[i][j]);
                m[grid[i][j]]+=1;
            }
            m[grid[i][j]]=1;
        }
    }
    for(int i=1;i<=n*n;i++)
    {
        if(m.find(i)== m.end())
        {
            ans.push_back(i);
            break;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid = {{1,2},{2,3}};
    vector<int> ans = findMissingAndRepeatedValues(grid);
    for(auto i : ans)
    {
        cout<< i << " ";
    }
    cout<< endl; 
    return 0;
}