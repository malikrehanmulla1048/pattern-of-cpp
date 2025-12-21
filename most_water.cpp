#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int most_water_brute_force(const vector<int>& height)
{
    int max_height=INT_MAX;
    int max_area=INT_MIN;
    int n=height.size();
    int min_height=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int width=0;
        for(int j=i;j<n;j++)
        {
            min_height=min(height[i],height[j]);
            max_area=max(max_area,min_height*width);
            width++;
        }
    }
    return max_area;
}
int maxArea_2_pointer_form(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int max_area=0;
        int min_height=INT_MAX;
        while(l<r)
        {
            min_height=min(height[l],height[r]);
            max_area=max(max_area,(r-l)*min_height);
            if(height[l]<height[r])
            {
                l++;
            }
            else if(height[l]>height[r])
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return max_area;
    }
int main()
{
    vector<int> height={1,8,6,2,5,4,8,3,7,9};
    int max_area=most_water_brute_force(height);
    cout<<"the maximum area of water that can be contained is: "<<max_area<<endl;
    max_area=maxArea_2_pointer_form(height);
    cout<<"the maximum area of water that can be contained using 2 pointer approach is:"<<max_area<<endl;
    return 0;
}