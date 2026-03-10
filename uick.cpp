#include<iostream>
#include<vector>
using namespace std;
int pivot (vector<int> &arr,int st,int end)
{
    int idx = st-1;
    int pivot_num = arr[end];
    for(int i=st; i <end;i++)
    {
        if(arr[i] <= arr[end])
        {
            idx ++;
            swap(arr[idx],arr[i]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}
void Sort1(vector<int> &arr,int st,int end)
{
    int pivot_idx;
    if(st<end)
    {
        pivot_idx = pivot(arr , st , end);
        Sort1(arr , st ,pivot_idx -1);
        Sort1(arr, pivot_idx+1 , end);
    }
     
}
void uickSort(vector<int> &arr)
{
    int st,end;
    st =0;
    end =arr.size()-1 ;
    Sort1(arr , st , end);
}
int main(){
    vector<int> arr ={28,1,45,6,22};
    uickSort(arr);
    for(int num:arr)
    {
        cout<<num<<"\t";
    }
    return 0;

}