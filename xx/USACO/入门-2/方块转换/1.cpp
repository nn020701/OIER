#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
string st,ed;
string r90(string rect)
{
    string ret=rect;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ret[j*n+n-1-i]=rect[i*n+j];
    return ret;
}
string r180(string rect){return r90(r90(rect));}
string r270(string rect){return r90(r90(r90(rect)));}
string fz (string rect)
{
    string ret=rect;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ret[i*n+j]=rect[i*n+(n-j-1)];
    return ret;
}
int main ()
{
    cin>>n;
    string tmp;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        st+=tmp;
    }
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        ed+=tmp;
    }
    if(r90(st)==ed)
        cout<<1;
	else if(r180(st)==ed)
        cout<<2;
    else if(r270(st)==ed)
        cout<<3;
    else if((tmp=fz(st))==ed)
        cout<<4;
    else if(r90(tmp)==ed||r180(tmp)==ed||r270(tmp)==ed)
        cout <<5;
    else if(st==ed)
        cout<<6;
    else
        cout<<7;
    return 0;
}
