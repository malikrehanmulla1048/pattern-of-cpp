#include<iostream>
using namespace std;
int gcdn(int a, int b )
{
    if(b==0) return a;
    return gcdn(b,a%b);
    return b;
}
int main()
{
    int num1=25;
    int num2=50;
    int gcd1=gcdn(num1,num2);
    cout<< gcd1<<endl;
    int lcm= num1*num2/gcd1;
    cout<<"the lcm is::"<<lcm<<endl;
}