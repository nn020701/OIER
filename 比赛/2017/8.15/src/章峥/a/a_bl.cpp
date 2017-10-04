#include<fstream>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.ans");
const int N=1005;
int a[N][N];
long long s1[N][N],s2[N][N];
int main()
{
	int n,w;
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
	int ans;
	for(ans=n;ans;ans--)
	{
		bool flag=false;
		for(int i=1;!flag&&i+ans-1<=n;i++)
			for(int j=1;!flag&&j+ans-1<=n;j++)
			{
				long long sum=s1[i+ans-1][j+ans-1]-s1[i-1][j-1]+s2[i+ans-1][j]-s2[i-1][j+ans];
				if(ans&1)
					sum-=a[i+ans/2][j+ans/2];
				if(sum<=w)
					flag=true;
			}
		if(flag)
			break;
	}
	fout<<ans<<endl;
	return 0;
}