#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;

bool pd(int m){
	int p = 0;
	for(int i = n;i > k;i--){
		p = (p+m%i)%i;
		if(p < k) return false;
	}
	return true;
}

int main(){
	k = read(); n = k*2;
	for(int i = 1;;i++)
		if(pd(i)){
			printf("%d\n",i+1);
			break;
		}
	return 0;
}
