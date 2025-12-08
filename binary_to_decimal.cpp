#include<iostream>
using namespace std;
int binarytodecimal(int n)
{
    int ans=0;
    
    int power=1;
    while(n>=0)
    {
        int reminder=n%10;
        ans+=reminder*power;
        power*=2;
        n=n/10;
    }
    return ans;
}
int main()
{
    cout<<"Binary to Decimal Conversion:"<<"\n";
    cout<< binarytodecimal(1) <<"\n";
    cout<<"binarytodecima"<<"\n";
    return 0;
}