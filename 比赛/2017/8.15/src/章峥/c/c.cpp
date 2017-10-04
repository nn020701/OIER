#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("c.in");
ofstream fout("c.out");
const int N=100005;
struct joke
{
	int x,type,d;
}a[N];
int vis[N];
int main()
{
	int n,m;
	fin>>n>>m;
	for(int i=1;i<=m;i++)
		fin>>a[i].x>>a[i].type>>a[i].d;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		bool state=true;
		for(int j=1;j<=m;j++)
			if(abs(i-a[j].x)<=a[j].d)
				if(vis[a[j].type]<i)
				{
					state=false;
					vis[a[j].type]=i;
				}
				else
					state=true;
		ans+=state;
	}
	fout<<ans<<endl;
	return 0;
}