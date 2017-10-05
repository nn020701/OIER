#include<bits/stdc++.h>
using namespace std;
int ans;
int main()
{
	//freopen("cs.out","w",stdout);
	/*for (int i=0;i<=31;++i)
	{
		int x=i;
		for (int j=1;j<=5;++j)
		{
			if (j==1)
				ans=x&1;
			else
				ans=!(ans&(x&1));
			putchar('0'+(x&1));
			x/=2;
		}
		putchar('\n');
		printf("%d\n",ans);
	}*/
	for (int j=1;j<=5;++j)
	{
		char c=getchar();
		if (j==1)
			ans=c-'0';
		else
			ans=!(ans&(c-'0'));
	}
	cout<<ans;
	/*set<int> s;
	s.insert(0);
	s.insert(50);
	set<int>::iterator it=s.lower_bound(100);
	if (it==s.end())
		puts("233");
	printf("%d\n",*--it);
	printf("%d",*it);*/
}