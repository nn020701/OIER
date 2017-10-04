#include<fstream>
#include<ctime>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
const int N=1005;
int n,w,a[N][N];
long long s1[N][N],s2[N][N];
bool check(int ans)
{
	for(int i=1;i+ans-1<=n;i++)
		for(int j=1;j+ans-1<=n;j++)
		{
			long long sum=s1[i+ans-1][j+ans-1]-s1[i-1][j-1]+s2[i+ans-1][j]-s2[i-1][j+ans];
			if(ans&1)
				sum-=a[i+ans/2][j+ans/2];
			if(sum<=w)
				return true;
		}
	return false;
}
int main()
{
	fin>>n>>w;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			fin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			s1[i][j]=s1[i-1][j-1]+a[i][j];
			s2[i][j]=s2[i-1][j+1]+a[i][j];
		}
	int l=0,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
			r=mid-1;
	}
	//ans is lower_bound
	for(int i=ans;i<=n&&clock()<=800;i++)
		if(check(i))
			ans=i;
	fout<<ans<<endl;
	return 0;
}