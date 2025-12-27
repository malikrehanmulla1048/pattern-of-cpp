#include <iostream>
#include <vector>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
        int start =0;
        int mid;
        int end = nums.size()-1;
        while (start <= end)
        {
            mid= start + (end-start)/2;
            if (mid==0 || mid== nums.size()-1 )
            {
                return nums[mid];
            }
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            {
                return nums[mid];
            }
            if (((end-start)/2) % 2 ==0)
            {
                if (nums[mid]==nums[mid-1])
                {
                    end = mid-2;
                }
                else
                {
                    start = mid+2;
                }
            }
            else
            {
                if (nums[mid]==nums[mid-1])
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
        }
        return nums[0];
    }