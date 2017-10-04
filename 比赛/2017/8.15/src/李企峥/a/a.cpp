#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Rep(i,a,b) for (int i=b;i>=a;i--)
using namespace std;
int n,w,a[1010][1010],f[1010][1010],g[1010][1010];
int x,y;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read();w=read();
	For(i,1,n)
		For(j,1,n)
			a[i][j]=read();
	For(i,1,n)
		For(j,1,n)
			f[i][j]=f[i-1][j-1]+a[i][j];
	For(i,1,n)
		For(j,1,n)
			g[i][j]=g[i-1][j+1]+a[i][j];
	/*For(i,1,n)
		{
			For(j,1,n)cout<<g[i][j]<<" ";	
			cout<<endl;
		}*/
	Rep(ans,1,n)
	{
		if(ans%2==1)y=1;else y=0;
		For(i,1,n-ans+1)
			For(j,1,n-ans+1)
			{
				x=f[i+ans-1][j+ans-1]-f[i-1][j-1];
				x=x+g[i+ans-1][j]-g[i-1][j+ans-2];
				x-=(y*a[i+(ans/2)+1][j+(ans/2)+1]);
				if(x<=w)
				{
					cout<<ans<<endl;
					return 0;
				}
			}
	}
	cout<<0<<endl;
	return 0;
}

