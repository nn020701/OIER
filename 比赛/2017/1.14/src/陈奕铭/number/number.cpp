#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int m_num[10];
int num[10];
int n_num[10];
int book[10];
int l[10];
bool flag=true;
void js(int k)
{
	int x;
	while(k!=0)
	{
		x=k%10;
		k=k/10;
		num[x]++;
	}
}
bool func()
{
	return n_num[0]>=0&&n_num[1]>=0&&n_num[2]>=0&&n_num[3]>=0&&n_num[4]>=0&&n_num[5]>=0&&n_num[6]>=0&&n_num[7]>=0&&n_num[8]>=0&&n_num[9]>=0;
}
bool funb()
{
	return n_num[0]==0&&n_num[1]==0&&n_num[2]==0&&n_num[3]==0&&n_num[4]==0&&n_num[5]==0&&n_num[6]==0&&n_num[7]==0&&n_num[8]==0&&n_num[9]==0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=9;i++)
		cin>>m_num[i];
	int p;
	int k;
	int lll;
	int ll;
	for(int i=1;i<=1040;i++)
	{
		js(i);
		for(int j=0;j<=9;j++)
			n_num[j]=num[j]-m_num[j];
		if(func())
		{
			for(int j=1;j<=i;j++)
			{
				ll=j;
				while(ll!=0)
				{
					n_num[ll%10]--;
					ll/=10;
				}
				if(funb())
				{
					cout<<i<<" "<<j<<endl;
					flag=false;
				}
				for(int z=0;z<=9;z++)
					n_num[z]=num[z]-m_num[z];
			}
		}	
	}
	if(flag)
		cout<<"NO ANSWER\n";
	return 0;
}
