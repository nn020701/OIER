#include<bits/stdc++.h>
using namespace std;
const int N=105;
char c[N],ch;
int f[N][11],len,ans,p,k;
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ch=getchar();
	while (ch!=EOF)
	{
		len=0;
		while (ch!='\n'&&ch!=EOF)
		{
			c[++len]=ch;
			ch=getchar();
		}
		memset(f,0x3f,sizeof(f));
		f[0][6]=0;
		for (int i=1;i<=len;++i)
		{
			p=c[i]-'0';
			if (p==0)
				p=10;
			if (i==1)
				k=5;
			else
				k=c[i-1]-'0';
			if (k==0)
				k=10;
			for (int j=1;j<k;++j)
			{
				for (int l=1;l<p;++l)
					f[i][l]=min(f[i][l],f[i-1][j]+1+max(abs(j-l)-1,abs(p-k)));
				for (int l=p+1;l<=10;++l)
					f[i][l]=min(f[i][l],f[i-1][j]+1+max(abs(p-j),abs(k-l)-1));
			}
			for (int j=k+1;j<=10;++j)
			{
				for (int l=1;l<p;++l)
					f[i][l]=min(f[i][l],f[i-1][j]+1+max(abs(p-j),abs(k-l)-1));
				for (int l=p+1;l<=10;++l)
					f[i][l]=min(f[i][l],f[i-1][j]+1+max(abs(j-l)-1,abs(p-k)));
			}	
		}		
		ans=(int)1e9+7;
		for (int i=1;i<=10;++i)
				ans=min(ans,f[len][i]);
		printf("%d",ans);
		putchar('\n');
		ch=getchar();
	}
	return 0;
}