#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

inline void write(ll x){
	if(x<0){putchar('-'); x=-x;}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
void writeln(ll x){
	write(x);
	puts("");
}

ll n,num;
ll f[25][10];
ll a[25];
ll bin[19]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,
			10000000000000,100000000000000,1000000000000000,10000000000000000,100000000000000000,1000000000000000000};

void dp(){
	for(ll i=0;i<=9;i++)
		f[1][i]=0;
	for(ll k=2;k<=20;k++)
		for(ll i=0;i<=9;i++)
			for(ll j=0;j<=9;j++){
				if(i==4&&j==9) f[k][i]+=bin[k-2];
				else f[k][i]+=f[k-1][j];
			}
}

void shu(){
	ll ans=0,q=0;
	for(ll i=num;i>=1;i--){
		if(a[i+1]==9&&a[i+2]==4){
			ll x=0;
			for(ll k=i;k>=1;k--) x=x*10+a[k];
			ans+=x+1;
			write(ans);
			return;
		}
		if(i==1)
			for(ll j=0;j<=a[i];j++)
				ans+=f[i][j];
		else
			for(ll j=0;j<a[i];j++)
				ans+=f[i][j];
	}
	if(a[1]==9&&a[2]==4)
		ans++;
	write(ans);
}

int main(){
	freopen("lucky.in","r",stdin);
	freopen("lucky.out","w",stdout);
	char ch[25];
	scanf("%s",ch);
	num=strlen(ch);
	for(ll i=num;i>=1;i--)
		a[i]=ch[num-i]-'0';
	dp();
	shu();
	return 0;
}