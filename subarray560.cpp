#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int subarraysum(vector<int>& nums, int k)
{
    long long sum=0;
    int count=0;
    unordered_map<long long,int> mp;
    mp[0]=1;
    for(auto i:nums)
    {
        sum+=i;
        if(mp.find(sum-k)!=mp.end())
        {
            count+=mp[sum-k];
        }
        mp[sum]++;
    }
    return count;
}
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int tot = 0;
    for(int i = 0; i < n; i++) {
        long long sum = 0;
        for(int j = i; j < n; j++) {
            sum += nums[j];
            if(sum == k) tot++;
        }
    }
    return tot;
}


int main()
{
    vector<int> nums = {1,1,1};
    int k = 2;
    cout<<subarraysum(nums,k);
    return 0;
}