#include<iostream>
#include<string>
using namespace std;
bool isMatch(string s, string p) {
         
        if (s.size() > p.size())
        {
            cout<<"this";
            return false;
        }
        else
        {
            for(int i=0,j=0;i<s.size() && j<p.size();i++,j++)
            {
                if(p[j]=='*')
                {
                    j++;
                }
                 
                if(s[i]!=p[j] && p[j]!='.')
                {
                    if(j+1==p.size())
                    {
                        return false;
                    }
                    if(p[j+1]!='*')
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
int main()
{
    string s="aa";
    string p="a*";
    cout<<isMatch(s,p);
    return 0;
}