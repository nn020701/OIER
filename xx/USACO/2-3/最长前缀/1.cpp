#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;

const unsigned long long POW[]={1,26,676,17576,456976,11881376,308915776,8031810176,208827064576,5429503678976,141167095653376,3670344486987776};

struct Val
{
	unsigned long long val;
	int zero;
	Val(unsigned long long _val,int _zero)
	{
		val=_val;
		zero=_zero;
	}
	Val(){}
	friend bool operator< (Val a,Val b)
    {
    	return (a.val!=b.val)?(a.val<b.val):(a.zero<b.zero);
    }
};

int cnt=0;
int best=0;
int dp[200005];
string dest;
string s[205];
map<Val,bool> m;

Val con_secll(int l,int r)
{
	bool flag=true;
	unsigned long long ans=0;
	int zero=0;
	for(int i=r;i>=l;i--)
	{
		ans+=(dest[i]-'A')*POW[i-l];
		if(flag) zero++;
		else flag=false;
	}
	return Val(ans,zero);
}

Val con_sll(string s)
{
	bool flag=true;
	unsigned long long ans=0;
	int zero=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		ans+=(s[i]-'A')*POW[i];
		if(flag) zero++;
		else flag=false;
	}
	return Val(ans,zero);
}

void read()
{
	string temp;
	while(cin>>temp)
	{
		if(temp==".") break;
		Val index=con_sll(temp);
		m[index]=true;
		cnt++;
	}
	while(cin>>temp)
		dest+=temp;
}

void print_sec(int l,int r)
{
	for(int i=l;i<=r;i++)
		cout<<dest[i];
	cout<<endl;
}
void set_dp()
{
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(int i=1,t=dest.size();i<=t;i++)
	{
		for(int j=i-1;j>=i-12;j--)
		{
			if(dp[j]==-1) continue;
			Val now=con_secll(j,i-1);
			if(m[now]!=false)
			{
				dp[i]=i;
				best=max(best,dp[i]);
				break;
			}
		}
	}
}

void test()
{
	string s;
	while(cin>>s)
	{
		cout<<con_sll(s).val<<endl;
	}
}
void test_2()
{
	int l,r;
	cin>>dest;
	while(cin>>l>>r)
	{
		print_sec(l,r);
		cout<<con_secll(l,r).val<<endl;
	}
}
int main()
{
	read();
	set_dp();
	cout<<best<<endl;
}
