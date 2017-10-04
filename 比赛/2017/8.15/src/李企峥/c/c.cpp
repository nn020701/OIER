#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Rep(i,a,b) for (int i=b;i>=a;i--)
using namespace std;
int n,m,x,l,k;
map<int,int>a[10000000];
bool f[100000];
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read();m=read();
	For(i,1,n)f[i]=false;
	For(i,1,m)
	{
		x=read();l=read();k=read();
		For(j,max(1,x-k),min(x+k,n))
		{
			if(a[j][l]==false)
			{
				f[j]=true;
				a[j][l]=true;
			}
			else
			{
				f[j]=false;
			}
		}
		/*For(j,x+1,)
		{
			if(a[j][l]==false)
			{
				f[j]=true;
				a[j][l]=true;
			}
			else
			{
				f[j]=false;
			}
		}*/
	}
	int ans=0;
	For(i,1,n)if(f[i]==false)ans++;
	cout<<ans<<endl;
	return 0;
}

