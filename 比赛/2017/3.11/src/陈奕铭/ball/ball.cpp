#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-'); x=-x;}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
void writeln(int x){
	write(x);
	puts("");
}

struct data{
	int a,b;
}p,q;



int a,b;
int ans;
map<data,bool> m;

bool operator <(data a,data b){
	return (a.a<b.a)||(a.a==b.a&&a.b<b.b);
}

int gcd(int x,int y){
	if(x%y==0) return y;
	return gcd(y,x%y);
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	a=read(); b=read();
	if((a+b)%2!=0){
		write(-1);
		return 0;
	}
	if(a<b) swap(a,b);
	int g=gcd(a,b);
	a/=g; b/=g;
	while(1){
		if(a==b){
			write(ans+1);
			return 0;
		}
		p.a=a; p.b=b;
		if(m[p]){
			write(-1);
			return 0;
		}
		m[p]=true;
		a-=b; b*=2;
		if(a<b) swap(a,b);
		g=gcd(a,b); a/=g; b/=g;
		ans++;
	}
	return 0;
}