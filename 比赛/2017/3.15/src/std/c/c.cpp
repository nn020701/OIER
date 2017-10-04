#include<cstdio>
using namespace std;
const int N=100100,P=1000000007;
int f[11][N],T[11][N],num[11][N],a[N];
char s[10];
int i,j,k,n,m,ch,x,y,ans;
void R(int &x)
{
	x=0;ch=getchar();
	while (ch<'0' || '9'<ch) ch=getchar();
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
}
int Lb(int x) {return x&(-x);}
void T_add(int k,int x,int y)
{
	for (;x<=n;x+=Lb(x)) (T[k][x]+=y)%=P;
}
int T_query(int k,int x)
{
	int t=0;
	for (;x;x-=Lb(x)) (t+=T[k][x])%=P;
	return t;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	R(n);R(m);R(m);
	for (i=1;i<=n;i++) f[1][i]=i;
	for (i=2;i<=10;i++)
		for (j=1;j<=n;j++) f[i][j]=(f[i-1][j]+f[i][j-1])%P;
	for (i=1;i<=n;i++) num[1][i]=1;
	for (i=2;i<=10;i++)
		for (j=n;j;j--) num[i][j]=(num[i-1][j]+num[i][j+1])%P;
	for (i=1;i<=n;i++)
	{
		R(a[i]);
		for (j=1;j<=10;j++) T_add(j,i,1ll*a[i]*num[j][i]%P);
	}
	for (i=1;i<=m;i++)
	{
		scanf("%s",s);
		if (s[0]=='Q')
		{
			R(y);R(x);
			if (!y) printf("%d\n",a[x]);
			else
			{
				ans=T_query(y,x);
				for (j=n-x,k=1;k<y && j;j--,k++)
				{
					if (k&1) (ans+=P-1ll*f[k][j]*T_query(y-k,x)%P)%=P;
					else (ans+=1ll*f[k][j]*T_query(y-k,x)%P)%=P;
				}
				printf("%d\n",ans);
			}
		}
		else
		{
			R(x);R(y);
			(a[x]+=y)%=P;
			for (j=1;j<=10;j++) T_add(j,x,1LL*y*num[j][x]%P);
		}
	}
}
