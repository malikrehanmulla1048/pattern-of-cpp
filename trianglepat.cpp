#include<iostream>
using namespace std;
// int main()
// {
//     int n;
//     cout<<"enter the number of the star lines:"<<"\n"<<">>";
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=i;j++)
//         {
//             cout<<'*'<<"\t";
//         }
//     cout<<endl;
//     }
//     return 0;
// }
// int main()
// {
//     int n;
//     cout<<"enter the number of the lines:"<<"\n"<<">>";
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=i;j>0;j--)
//         {
//             cout<<j<<"\t";

//         }
    
//     cout<<endl;
//     }
//     return 0;
// }
int main()
{
    int n,m=1;
    cout<<"enter the number of the lines:"<<"\n";
    cin>>n;
    cout<<"\n----------------------------------\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<m<<"\t";
            m++;
        }
        cout<<endl;
    }
    return 0;
}