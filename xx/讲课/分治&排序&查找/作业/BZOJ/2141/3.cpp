#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	int n=rand()%20000+1;
	cout<<n<<endl;
	for(int i=1;i<=n;i++)
		cout<<rand()%100000000+1<<" ";
	cout<<endl;
	int m=rand()%2000+1;
	cout<<m<<endl;
	int a,b;
	for(int i=1;i<=m;i++)
	{
		a=rand()%n+1;
		b=rand()%n+1;
		while(a==b)
			b=rand()%n+1;
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}
