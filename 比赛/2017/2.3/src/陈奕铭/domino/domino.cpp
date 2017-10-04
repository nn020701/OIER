#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int x[10010],y[10010];
int n;
int up,down;
bool flag=false;
int main(){
	freopen("domino.in","r",stdin);
	freopen("domino.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read();y[i]=read();
		up=(up+x[i])%2;
		down=(down+y[i])%2;
		if((x[i]%2==0&&y[i]%2!=0)||(x[i]%2!=0&&y[i]%2==0))
			flag=true;
	}
	if((up%2==0&&down%2!=0)||(up%2!=0&&down%2==0))
		cout<<"-1"<<endl;
	else if(up%2==0&&down%2==0)
		cout<<"0"<<endl;
	else{
		if(flag)
			cout<<"1"<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
