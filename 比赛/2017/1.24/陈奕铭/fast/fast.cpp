#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
struct data{
	int a[300];
	int length;
}ans[500],er[510],num;
int n;
void add(int k)
{
	num.length=max(ans[k].length,num.length);
	for(int i=1;i<=num.length;i++)
	{
		num.a[i]+=ans[k].a[i];
		if(num.a[i]>=10)
		{
			num.a[i+1]+=num.a[i]/10;
			num.a[i]%=10;
		}
	}
	while(num.a[num.length+1]>0)
		num.length++;
}
void qiu(int k)
{
	ans[k]=er[k+1];
	int i=1;
	bool flag=true;
	while(flag)
	{
		flag=false;
		if(ans[k].a[i]==0)
		{
			ans[k].a[i]+=10;
			flag=true;
		}
		ans[k].a[i]--;
		i++;
	}
}
void cheng(int k)
{
	er[k].length=er[k-1].length;
	for(int i=1;i<=er[k].length;i++)
		er[k].a[i]=2*er[k-1].a[i];
	for(int i=1;i<=er[k].length;i++)
		if(er[k].a[i]>=10)
		{
			er[k].a[i+1]+=er[k].a[i]/10;
			er[k].a[i]%=10;
		}
	if(er[k].a[er[k].length+1]>0)
		er[k].length++;
}
int main()
{
	freopen("fast.in","r",stdin);
	freopen("fast.out","w",stdout);
	er[0].a[1]=0;
	er[0].length=1;
	er[1].a[1]=1;
	er[1].length=1;
	ans[0].a[1]=0;
	ans[0].length=1;
	num.a[1]=0;
	num.length=1;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		cheng(i);
	for(int i=1;i<=n-1;i++)
		qiu(i);
	char s[510];
	scanf("%s",s);
	for(int i=0;i<n;i++)
		if(s[i]=='1')
			add(n-i-1);
	for(int i=num.length;i>=1;i--)
		printf("%d",num.a[i]);
	return 0;
}
