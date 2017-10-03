#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct data{
	string name;
	int give;
	int accept;
}a[20];
int n;
int pd(string name)
{
	for(int i=1;i<=n;i++)
		if(name==a[i].name)
			return i;
}
int main()
{
	cin>>n;
	int k,l,z;
	string name;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].name;
		a[i].accept=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>name;
		k=pd(name);
		cin>>a[k].give>>l;
		for(int j=1;j<=l;j++)
		{
			cin>>name;
			z=pd(name);
			a[z].accept+=a[k].give/l;
		}
		if(l!=0)
			a[k].accept+=a[k].give%l; 
	}
	for(int i=1;i<=n;i++)
		cout<<a[i].name<<" "<<a[i].accept-a[i].give<<"\n";
	return 0;
}
