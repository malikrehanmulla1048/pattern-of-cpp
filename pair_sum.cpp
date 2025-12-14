#include<iostream>
#include<vector>
using namespace std;
vector<int> pairSum(vector<int> &arr, int tar)
{
    int i=0,j=arr.size()-1;
    vector<int> pair;
    while(i<j)
    {
        if(arr[i]+arr[j]==tar)
        {
             
            pair.push_back(arr[i]);
            pair.push_back(arr[j]);
            return pair;
        }
        else if(arr[i]+arr[j]<tar)
        {
            i++;

        }
        else
        {
            j--;
        }
    }
    return pair;
}
int main()
{
    vector<int> arr={2,3,5,6,9,10};
    int tar=11;
    vector<int> ans=pairSum(arr,tar);
    cout<<"the pair is ("<<ans[0]<<","<<ans[1]<<")"<<endl;
    return 0;
}