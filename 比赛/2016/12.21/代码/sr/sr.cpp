#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string sr;
int main()
{
	freopen("sr.in","r",stdin);
	freopen("sr.out","w",stdout);
	cin>>sr;
	int stack[100010];
	int top=0;
	for(int i=0;i<sr.length();i++)
	{
		stack[++top]=sr[i];
		if(top>=3)
		{
			if(stack[top]=='R'&&(stack[top-1]=='S'&&stack[top-2]=='S'))
				top=top-3;
		}
	}
	cout<<top<<endl;
	return 0;
}
