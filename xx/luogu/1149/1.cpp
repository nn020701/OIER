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

const int p[10] = {6,2,5,5,4,5,6,3,7,6};
int ans,n;

int get(int num){
	int x = num;
	int sum = 0;
	while(x){
		sum += p[x%10];
		x /= 10;
	}
	if(num == 0) sum = 6;
	return sum;
}

int main(){
	n = read()-4;
	for(int i = 0;i <= 1000;i++)
		for(int j = 0;j <= 1000;j++)
			if(get(i)+get(j)+get(i+j) == n)
				ans++;
	printf("%d\n",ans);
	return 0;
}
