#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int p[4];
	int life;
}a,b;
int top;
int s[1010];
int round;
int n;
int a_l,b_l;
void Init()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	top=0;
	round=0;
	a.p[1]=0;
	a.p[2]=0;
	a.p[3]=0;
	b.p[1]=0;
	b.p[2]=0;
	b.p[3]=0;
	for(int i=0;i<3;i++)
	{
		a.p[s[top]]++;
		top=(top+1)%n;
	}
	for(int i=0;i<3;i++)
	{
		b.p[s[top]]++;
		top=(top+1)%n;
	}
	cin>>a_l>>b_l;
	a.life=a_l;
	b.life=b_l;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	Init();
	bool flag;
	while(a.life!=0&&b.life!=0)
	{
		round++;
		a.p[s[top]]++;
		top=(top+1)%n;
		if(a.p[1]!=0)
		{
			a.p[1]--;
			if(b.p[2]>0)
				b.p[2]--;
			else
			{
				b.life--;
				if(b.life==0)
				{
					flag=true;
					break;
				}
			}
		}
		while(a.life<a_l&&a.p[3]>0)
		{
			a.life++;
			a.p[3]--;
		}
		b.p[s[top]]++;
		top=(top+1)%n;
		if(b.p[1]!=0)
		{
			b.p[1]--;
			if(a.p[2]>0)
				a.p[2]--;
			else
			{
				a.life--;
				if(a.life==0)
				{
					flag=false;
					break;
				}
			}
		}
		while(b.life<b_l&&b.p[3]>0)
		{
			b.life++;
			b.p[3]--;
		}
	}
	if(flag)
		cout<<"AWIN! "<<round<<endl;
	else
		cout<<"BWIN! "<<round<<endl;
	return 0;
}
