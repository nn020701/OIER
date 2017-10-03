#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string s1,s2;
int ans1=1,ans2=1;
int main()
{
	cin>>s1>>s2;
	for(int i=0;i<s1.length();i++)
		ans1=ans1*(s1[i]-'A'+1)%47;
	for(int i=0;i<s2.length();i++)
		ans2=ans2*(s2[i]-'A'+1)%47;
	if(ans1==ans2)
		cout<<"GO\n";
	else
		cout<<"STAY\n";
	return 0;
}
