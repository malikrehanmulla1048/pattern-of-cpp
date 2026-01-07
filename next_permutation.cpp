#include<iostream>
#include<vector>
using namespace std;
void next_permutation(vector<int> &nums)
{
    int  ch;
    int n = nums.size();
    // for(int  i = n-1 ; i >= 0; i--)
    // {
    //     if(i>0 && nums[i-1] < nums[i])
    //     {
    //         swap(nums[i-1] , nums[n-1]);
    //         ch = i;
    //         break;
    //     }
    // }
    int i = n-1;
    int end2 = n-1;
    while(i>=0)
    {
        if(i>0 && nums[i-1] < nums[i])
        {
            if(nums[end2]>nums[i-1])
            {
                swap(nums[i-1] , nums[end2]);
                ch = i;
                break;
            }
            else
            {
                end2--;
                continue;
            }
        }
        i--;
    }
    int st = ch , end = n-1;
    while(st <= end)
    {
        swap(nums[st] , nums[end]);
        st++;
        end--;
    }
}
int main()
{ 
    vector<int> nums = {5,4,2,3,1};
    next_permutation(nums);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}