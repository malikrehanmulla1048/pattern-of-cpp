#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> productExceptSelf(const vector<int>& nums)
{
    vector<int> result={};
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        int prod=1;
        for(int j:nums)
        {
            if(j!=nums[i])
            {
            prod*=j;
            }
        }
        result.push_back(prod);
    }
    return result;
}
vector<int> productExceptSelf2(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n,1);
        int suffix=1;
        for(int i=1;i<n;i++)
        {
            answer[i]=answer[i-1]*nums[i-1];

        }
        for(int i=n-1;i>=0;i--)
        {
            answer[i]=answer[i]*suffix;
            suffix*=nums[i];
        }
         
        return answer;
    }
int main(){
    vector<int> nums={1,2,3,4};
    vector<int> result2=productExceptSelf2(nums);
    vector<int> result1=productExceptSelf(nums);
    cout<<"the product of array except self (by the brute force method) is: ";
    for(int i:result1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"the product of array except self (with the help of the O(n) approach) is: ";
    for(int i:result2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
