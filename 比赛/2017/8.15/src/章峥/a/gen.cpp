#include<fstream>
#include<random>
#include<ctime>
using namespace std;
ofstream fout("a.in");
const int n=1000,w=1e9;
int main()
{
	minstd_rand gen(time(NULL));
	fout<<n<<' '<<w<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			uniform_int_distribution<> d(0,1e7);
			fout<<d(gen)<<' ';
		}
		fout<<endl;
	}
	return 0;
}