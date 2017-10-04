#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string n;
int k;
int a;
int main()
{
	freopen("len.in","r",stdin);
	freopen("len.out","w",stdout);
	int len;
	cin>>n>>k;
	a=n[0]-'0';
	if(a>=k)
		len=n.length();
	else
		len=n.length()-1;
	cout<<len<<endl;
	return 0;
}
