#include<iostream>
using namespace std;
void fibbonacci(int num)
{
    int a=0,b=1,c;
    for(int i=1;i<=num;i++)
    {
        cout<<a<<"\t";
        int c=a+b;
        a=b;
        b=c;
    }
}
int main()
{
    int n;
    cout<<"enter the number of the fibbonacci:"<<"\n";
    cin>>n;
    fibbonacci(n);
    cout<<"hello world";

    return 0;
}