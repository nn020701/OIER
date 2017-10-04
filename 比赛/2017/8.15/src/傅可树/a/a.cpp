#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e3+5;
int n,W;
ll s1[maxn][maxn],s2[maxn][maxn],a[maxn][maxn];
inline ll read(){ll x=0,f=1; char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();} while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} return x*f;}
inline void write(int x){if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10); putchar(x%10+'0');}
inline void writeln(int x){write(x); puts("");}
inline bool check(int x)
{
	int mid=x/2;
	for (int i=1;i<=n-x+1;i++){
		for (int j=1;j<=n-x+1;j++){
			ll s=s1[i][j]-s1[i+x][j+x]+s2[i][j+x-1]-s2[i+x][j-1];
			if (x&1){
				s-=a[i+mid][j+mid];
			}
			if (s<=W){
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	n=read(); W=read();
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	for (int i=n;i;i--){
		for (int j=n;j;j--){
			s1[i][j]=s1[i+1][j+1]+a[i][j];
		}
	}
	for (int i=n;i;i--){
		for (int j=1;j<=n;j++){
			s2[i][j]=s2[i+1][j-1]+a[i][j];
		}
	}
	int l=0,r=n;
	while (l<r){
		int mid=(l+r+1)>>1;
		if (check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	writeln(l*l);
}
