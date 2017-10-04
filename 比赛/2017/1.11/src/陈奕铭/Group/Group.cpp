#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int Max;
struct node{
	int x;
	int y;
	int book;
	int number;
}p[510];
int k;
int n;
int book[510];
bool cmp(const node &a,const node &b)
{
	return a.x<b.x;
}
void Init()
{
	cin>>n;
	k=0;
	int x,y;
	Max=0;
	bool flag;
	memset(p,0,sizeof(p));
	memset(book,0,sizeof(book));
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		if(x+y>=n||(x<0||y<0))
			continue;
		flag=true;
		for(int j=1;j<=k;j++)
			if(x==p[j].x&&y==p[j].y)
			{
				if(p[j].number<n-p[j].x-p[j].y)
					p[j].number++;
				flag=false;
				break;
			}
		if(flag)
		{
			k++;
			p[k].x=x;
			p[k].y=y;
			p[k].number=1;
		}
	}
	sort(p+1,p+k+1,cmp);
}
void dfs(int q,int num,int l)
{
	int o;
	for(int i=l;i<=k;i++)
	{
		if(p[i].x>=q&&book[i]!=1)
		{
			o=n-p[i].x-p[i].y;
			book[i]=1;
			dfs(q+o,num+p[i].number,i+1);
		}
	}
	if(num>Max)
		Max=num;
	return;
}
int main()
{
	freopen("Group.in","r",stdin);
	freopen("Group.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		Init();
		dfs(0,0,1);
		cout<<Max<<endl;
	}
	return 0;
}
