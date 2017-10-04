#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,q,p,m;

struct node{
	ll v[4][4];
	node(){
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				v[i][j]=0;
	}
};

node cheng(node a,node b){
	node tmp;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				tmp.v[i][k]=(tmp.v[i][k]+a.v[i][j]*b.v[j][k])%m;
	return tmp;
}

ll work(ll p,ll k){
	node a,b,c;
	b.v[1][1]=p; b.v[2][1]=1;
	b.v[2][2]=p; b.v[3][2]=1;
	b.v[3][3]=1;
	a.v[1][1]=a.v[2][2]=a.v[3][3]=1;
	while(k){
		if(k&1) a=cheng(a,b);
		b=cheng(b,b);
		k>>=1;
	}
	c.v[1][1]=(p*p)%m; c.v[2][1]=2*p;	c=cheng(a,c);
	return c.v[3][1];
}

int main(){
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	p=read(); q=read(); n=read(); m=read();
//	printf("%lld\n",n);
	ll ans1=work(p,n),ans2=work(q,n);
	printf("%lld\n",(ans1+ans2+ans1*ans2)%m);
	return 0;
}
