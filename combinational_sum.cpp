#include<iostream>
#include<vector>
#include<set>
using namespace std;
    set<vector<int>> s;
    void solve(vector<int>& candidates,
            vector<int> &ans,
            vector<vector<int>> &all_ans,
            int target,
            int i)
    {
        if(target <0 || i == candidates.size() ) return ;
        if(target  == 0)
        {
            if(s.find(ans) == s.end())
            {
                all_ans.push_back({ans});
                s.insert(ans);
            }
                return ;
            
        }
        
        ans.push_back(candidates[i]);
        solve(candidates,ans,all_ans,target-candidates[i],i+1);
        solve(candidates,ans,all_ans,target-candidates[i],i);
        ans.pop_back();
        solve(candidates,ans,all_ans,target,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> all_ans;
        solve(candidates,ans,all_ans,target,0);
        return all_ans;
    }
    int main()
    {
        vector<int> candidates = {2,3,6,7};
        int target = 7;
        vector<vector<int>> ans = combinationSum(candidates,target);
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }