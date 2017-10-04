#include<bits/stdc++.h>
#define get(x,y) (x-1)*m+y
using namespace std;
int a[100005];
int xxxx[10000];
int f[100005][15];
struct xxx{
	int x,y;
}t[100005];
int n,m;
bool com(xxx a,xxx b)
{
	return a.x*a.y>b.x*b.y;
}
bool check(int x,int y,int tx,int ty)
{
	int t=0;
	bool flag=false;
	for(int i=0;i<=9;i++){
		int tt=(f[get(tx,ty)][i]+f[get(x,y)][i]-f[get(tx,y)][i]-f[get(x,ty)][i]);
		if(tt%2!=0)t++;
		else if(i>0&&tt>0)flag=true;
	}
//	cout<<'!'<<flag<<' '<<t<<endl;
	return flag&t<2;
}
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read();
	m=read();
//	srand(time(0));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[get(i,j)]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			for(int k=0;k<=9;++k)f[get(i,j)][k]=f[get(i-1,j)][k]+f[get(i,j-1)][k]-f[get(i-1,j-1)][k];
			++f[get(i,j)][a[get(i,j)]];
		}
	int ans=1;
	int tt=0;
	for(int x=n;x>=1;x--)
		for(int y=m;y>=1;y--)
			tt++,t[tt].x=x,t[tt].y=y;
	sort(t+1,t+n*m+1,com);
	for(tt=1;tt<=n*m;tt++){
			int x=t[tt].x;
			int y=t[tt].y;
//			cout<<x<<' '<<y<<'!'<<endl;
			for(int i=1;i+x-1<=n;i++)
				for(int j=1;j+y-1<=m;j++)
					if(check(i-1,j-1,i+x-1,j+y-1)){
						printf("%d",x*y);
						return 0;
					}
		}
	return 0;
}
