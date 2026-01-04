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
vector<int> selectionSort(vector<int> &arr)
{
    //assuming that the first element is  the smallest element
    for(int i=0 ; i< arr.size()-1 ; i++)
    {
        for(int j=i+1 ; j< arr.size() ; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(arr[i] , arr[j]);
            }
        }
    }
    return arr;
}
vector<int> insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int  j = i - 1;
        while(arr[j] > arr[i])
        {
            int ch = arr[i];
            arr[i] = arr[j];
            if(j > 0)
            {
                j--;
            }
        }
    }
    return arr;
}
// vector<int> insertionSort2(vector<int> &arr)
// {
//     int position =0;
//     while(position < arr.size())
//     {
        
//     }
//     while()
// }
int main()
{
    vector<int> arr = {5, 3 , 2 , 1 , 4 };
    vector<int> sorted_array=sortArray(arr);
    for(int i=0 ; i< sorted_array.size() ; i++)
    {
        cout<<sorted_array[i]<< " ";
    }
    cout<<endl;
    vector<int> sortedArray2 = selectionSort(arr);
    for(int i=0 ; i< sortedArray2.size() ; i++)
    {
        cout<<sortedArray2[i]<< " ";
    }
    cout<<endl;
    vector<int> insertedArray = insertionSort(arr);
    for(int i=0 ; i<  insertedArray.size() ; i++)
    {
        cout<<insertedArray[i]<< " ";
    }
    return 0;
}