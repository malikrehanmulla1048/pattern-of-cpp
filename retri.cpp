#include<iostream>
using namespace std;
int main()
{
    int n,m=1;
    cout<<"enter the number of the lines:" <<"\n";
    cin>>n;
    cout<<"\n----------------------------------\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<"      ";
        }
        for(int j=(n-i);j>0;j--)
        {
            cout<<(i+1)<<"     ";
        }
        cout<<endl;
    } 
    
    return 0;
}