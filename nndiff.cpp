#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number of the rows:"<<">>"<<"\n"<<">>";
    cin>>n;
    char ch='A';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ch<<"\t";
            ch++;
        }
        cout<<endl;    }
    return 0;
}