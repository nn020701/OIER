#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct lian{
	char c;
	int next;
	int back;
}pp[60];
long long n,k;
string s;
int man;
int woman;
int main()
{
	freopen("dating.in","r",stdin);
	freopen("dating.out","w",stdout);
	cin>>s>>k;
	n=s.length();
	for(int i=0;i<n;i++)
	{
		pp[i].c=s[i];
		if(s[i]>='a'&&s[i]<='z')
			man++;
		else
			woman++;
		if(i==n-1)
			pp[i].next=0;
		else
			pp[i].next=i+1;
		if(i==0)
			pp[i].back=n-1;
		else
			pp[i].back=i-1;
	}
	if(man==0||woman==0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	char Min;
	int Min_n;
	int top=n-1;
	while(man>0&&woman>0)
	{
		int t=k%n;
		if(t==0)
			t+=n;
		for(int i=1;i<=t;i++)
			top=pp[top].next;
		if(pp[top].c>='a'&&pp[top].c<='z')
		{
			Min='Z';
			for(int j=pp[top].next;j!=top;j=pp[j].next)
				if(Min>=pp[j].c&&(pp[j].c>='A'&&pp[j].c<='Z'))
				{
					Min=pp[j].c;
					Min_n=j;
				}
			cout<<pp[top].c<<Min<<" ";
			pp[pp[Min_n].back].next=pp[Min_n].next;
			pp[pp[Min_n].next].back=pp[Min_n].back;	
			n--;
		}
		else
		{
			Min='z';
			for(int j=pp[top].next;j!=top;j=pp[j].next)
				if(Min>=pp[j].c&&(pp[j].c>='a'&&pp[j].c<='z'))
				{
					Min=pp[j].c;
					Min_n=j;
				}
			cout<<pp[top].c<<Min<<" ";
			pp[pp[Min_n].back].next=pp[Min_n].next;
			pp[pp[Min_n].next].back=pp[Min_n].back;	
			n--;
		}
		woman--;
		man--;
		n--;
		pp[pp[top].back].next=pp[top].next;
		pp[pp[top].next].back=pp[top].back;
	}
	return 0;
}
