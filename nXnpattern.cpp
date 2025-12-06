#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<< "enter the number of the nXn pattern:>>"<<"\n";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char ch='[';

        for(int j=1;j<=n;j++)
        {
            cout<< ch<< "\t";
            ch++;
        }
        cout<< "\n";
    }
    return 0;
}