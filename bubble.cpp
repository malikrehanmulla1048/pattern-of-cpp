#include<iostream>
#include<vector>
using namespace std;
vector<int> sortArray(vector<int> &arr)
{
    for(int i=0 ; i< arr.size()-1 ; i++)
    {
        for(int j=0 ; j< arr.size()-i-1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
    return arr;
}
int main()
{
    vector<int> arr = {5, 3 , 2 , 1 , 4 };
    vector<int> sorted_array=sortArray(arr);
    for(int i=0 ; i< sorted_array.size() ; i++)
    {
        cout<<sorted_array[i]<< " ";
    }

    return 0;
}