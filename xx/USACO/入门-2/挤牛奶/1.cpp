#include<iostream>
using namespace std;
bool p[1000010]={0};
int n;
int m1;
int m2;
int x,y;
int main()
{
	cin>>n;
	int a,b;
	x=1000010;
	y=0;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		for(int j=a;j<b;j++)
			p[j]=1;
		if(a<x)
			x=a;
		if(b>y)
			y=b;
	}
	int l1=0;
	int l2=0;
	for(int i=x;i<y;i++)
	{
		if(p[i]==0)
		{
			l1=0;
			l2++;
		}
		else
		{	
			l2=0;
			l1++;
		}
		if(l2>m2)
			m2=l2;
		if(l1>m1)
			m1=l1;
	}
	cout<<m1<<" "<<m2<<"\n";
	return 0;
}
