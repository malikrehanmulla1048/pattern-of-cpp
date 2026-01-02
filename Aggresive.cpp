#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossible(vector<int> &arr , int n ,int mid)
{
    int cows = 1;
    sort(arr.begin(), arr.end());

    int last_pos = arr[0];
    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] - last_pos >= mid)
        {
            last_pos = arr[i];
            cows++;
            
        }
    }
    return cows >= n;
    

}
int minStableDistance(vector<int> &arr, int m, int n)
{
    sort(arr.begin(), arr.end());
    int mid = 0;
    int ans = 0;
    int st = 0, end = arr.back() - arr.front();
    while(st <= end)
    {
        mid = st + (end - st)/2;
        if (isPossible(arr , n, mid))
        {
            st = mid+1;
            ans = mid;
        }
        else
        {
            end = mid-1;
        }

    }
    return ans;

}
int main()
{
    vector<int> arr = {1 ,2 ,8 ,4 ,9 };
    int n = 3;
    int m = 5;
    cout<<minStableDistance(arr, m, n);
    return 0;
}