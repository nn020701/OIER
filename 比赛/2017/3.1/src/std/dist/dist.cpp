#include<set>
#include<map>
#include<cmath>
#include<string>
#include<cstdio>
#include<vector>
#include<cctype>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fir first
#define sec second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

int IN()
{
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19,p=1e9+7;
int L=100000,n,x,tmp;

struct BIT
{
	int c[N];
	void Add(int x,int v)
	{
		for (;x<=L;x+=x&-x) (c[x]+=v)%=p;
	}
	int Query(int x)
	{
		int Ans=0;
		for (;x;x-=x&-x) (Ans+=c[x])%=p;
		return Ans;
	}
} B1,B2,S;

void Update(int x)
{
	B1.Add(x,p-x);
	B2.Add(L-x+1,x);
	S.Add(x,1);
}

int main()
{
	freopen("dist.in","r",stdin);
	freopen("dist.out","w",stdout);
	n=IN();
	For(i,1,n+1)
	{
		x=IN();
		Update(x);
		tmp=S.Query(x);
		printf("%d ",(B1.Query(x)+B2.Query(L-(x+1)+1)+1ll*x*tmp%p+1ll*(p-x)*(i-tmp)%p)%p);
	}
	puts("");
}