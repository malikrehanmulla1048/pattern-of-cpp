#include<iostream>
#include<vector>
using namespace std;
int MooresVoting(vector<int>& arr)
{
    int ans=0;
    int freq=1;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(freq==1)
        {
            ans=arr[i];
        }
        if(arr[i]==ans)
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr={1,2,2,2,1};
    int ans=MooresVoting(arr);
    cout<<ans<<endl;
}