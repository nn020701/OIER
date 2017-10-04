#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int L=200005;
char LZH[L],*S=LZH,*T=LZH;
inline char gc(){
	if (S==T){
		T=(S=LZH)+fread(LZH,1,L,stdin);
		if (S==T) return EOF;
	}
	return *S++;
}
inline int read(){
	int x=0,f=1;
	char c=gc();
	for (;c<'0'||c>'9';c=gc())
		if (c=='-') f=-1;
	for (;c>='0'&&c<='9';c=gc())
		x=(x<<1)+(x<<3)+c-48;
	return x*f;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout); 
	
}
