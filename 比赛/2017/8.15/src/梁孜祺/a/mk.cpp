#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
#define N 1005
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
int main(){
	freopen("a.in","w",stdout);
	srand(time(NULL));
	int n=rand()%10+1,k=rand()%30+1;
	cout<<n<<" "<<k<<endl;
	For(i,1,n){
		For(j,1,n){
			int x=rand()%7+1;
			printf("%d ",x);
		}
		puts("");
	}
	return 0;
}