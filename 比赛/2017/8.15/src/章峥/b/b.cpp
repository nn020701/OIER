#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream fin("b.in");
ofstream fout("b.out");
const int N=100,C=10;
int a[N][N],cnt[C];
int main()
{
	int n,m;
	fin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			fin>>a[i][j];
	int ans=0;
	for(int x1=1;x1<=n;x1++)
		for(int x2=x1;x2<=n;x2++)
			for(int y1=1;y1<=m;y1++)
				for(int y2=y1;y2<=m;y2++)
				{
					memset(cnt,0,sizeof(cnt));
					for(int i=x1;i<=x2;i++)
						for(int j=y1;j<=y2;j++)
							cnt[a[i][j]]++;
					int odd=0,even=0;
					for(int i=0;i<C;i++)
					{
						odd+=cnt[i]&1;
						even+=i&&cnt[i]&&cnt[i]%2==0;
					}
					if(odd<=1&&(cnt[0]==0||even))
						ans=max(ans,(x2-x1+1)*(y2-y1+1));
				}
	fout<<ans<<endl;
	return 0;
}