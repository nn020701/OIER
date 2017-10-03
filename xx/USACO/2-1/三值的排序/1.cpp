#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const char prog[] = "sort3";
char in[100],out[100];
const int MAX = 1005;
int ar[MAX];
int br[MAX];
int n;
int c[4][4]={0};
int csum=0;

int main(){
	n=read();
	for(int i=0;i<n;++i){
		ar[i]=read();
		br[i]=ar[i];
	}
	sort(br,br+n);
	for(int i=0;i<n;++i){
		if (ar[i]!=br[i]){
			++c[br[i]][ar[i]];
			++csum;
		}
	}
	int ans=0;
	for (int i=1;i<=3;++i)
		for (int j =i+1;j<=3;++j){
			int t=min(c[i][j],c[j][i]);
			ans+=t;
			c[i][j]-=t;
			c[j][i]-=t;
			csum-=2*t;
		}
	ans+=csum/3*2;
	cout<<ans<<endl;
	return 0;
}
