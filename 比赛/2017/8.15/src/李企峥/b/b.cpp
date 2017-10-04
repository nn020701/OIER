#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Rep(i,a,b) for (int i=b;i>=a;i--)
using namespace std;
int a[310][310],b[20];
int n,m,mx;
bool f[20];
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read();m=read();
	For(i,1,n)For(j,1,m)a[i][j]=read();
	mx=0;
	For(i1,1,n)
	{
		For(j1,1,m)
		{
			For(i2,i1,n)
				For(j2,j1,m)
				{
					if((i2-i1+1)*(j2-j1+1)<=mx)continue;
					For(i,0,9)b[i]=0,f[i]=false;
					For(i,i1,i2)
						For(j,j1,j2)
							b[a[i][j]]=b[a[i][j]] xor 1,f[i]=true;
					bool flag=false;
					For(i,1,9)
					{
						if(f[i]==true&&b[i]==0)flag=true;
					}
					int x=0;
					For(i,0,9)x+=b[i];
					if(x>1)continue;
					if(flag)mx=(i2-i1+1)*(j2-j1+1);
				}
		}
	}
	cout<<mx<<endl;
	return 0;
}

