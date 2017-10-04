#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
string s;
int ans,f,n,now;
bool flag=false;
int main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]=='F'&&flag){
			f++;
			ans=++now;
		}
		else if(s[i]=='M'){
			flag=true;
			if(f>0)
				f--;
			else
				now++;
		}
	}
	cout<<ans-1<<endl;
	return 0;
}