#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int flag[30];
int hash[30];
int book[60];
int n;
int t=0;
char l[60];
int weizhi[60];
string s;
void dfs(int p)
{
	if(p==n)
	{
		for(int i=0;i<n;i++)
			cout<<l[i];
		cout<<endl;
		exit(0);
	}
	int k;
	t++;
	if(t>2000000)
	{
		cout<<"NONE\n";
		exit(0);
	}
	for(int i=0;i<=25;i++)
	{
		if(flag[i]==0||hash[i]==1)
			continue;
		k=weizhi[i];
		k++;
		if(k==2*n)
			k=0;
		while(s[k]!=i+'A'&&book[k]!=1)
		{
			k++;
			if(k==2*n)
				k=0;
		}
		if(s[k]==i+'A')
		{
			book[weizhi[i]]=0;
			hash[i]=1;
			book[k]=1;
			l[p]=i+'a';
			dfs(p+1);
			book[weizhi[i]]=1;
			hash[i]=0;
			book[k]=0;
			l[p]=0;
		}
		k=weizhi[i];
		k--;
		if(k==-1)
			k=2*n-1;
		while(s[k]!=i+'A'&&book[k]!=1)
		{
			k--;
			if(k==-1)
				k=2*n-1;
		}
		if(s[k]==i+'A')
		{
			book[weizhi[i]]=0;
			hash[i]=1;
			book[k]=1;
			l[p]=i+'a';
			dfs(p+1);
			book[weizhi[i]]=1;
			hash[i]=0;
			book[k]=0;
			l[p]=0;
		}
	}
}
int main()
{
	freopen("park.in","r",stdin);
	freopen("park.out","w",stdout);
	cin>>s;
	n=s.length()/2;
	for(int i=0;i<2*n;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			flag[s[i]-'a']=1;
			weizhi[s[i]-'a']=i;
			book[i]=1;
		}
	}
	dfs(0);
	cout<<"NONE\n";
	return 0;
}