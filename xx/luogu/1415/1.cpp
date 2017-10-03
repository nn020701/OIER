#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 2505
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int num[505];
int f1[505],f2[505];
int n;

inline void Init(){
	char s[505];
	scanf("%s",s+1);
	n = strlen(s+1);
	for(int i = 1;i <= n;i++)
		num[i] = s[i]-'0';
}

inline bool bijiao(int l1,int r1,int l2,int r2){ //(l1,r1)是上一个,(l2,r2)是现在，是否现在大于上一个
	while(l1 <= r1 && num[l1] == 0) l1++;
	while(l2 <= r2 && num[l2] == 0) l2++;
	int len1 = r1-l1+1;
	int len2 = r2-l2+1;
	if(len1 == 0 || len2 == 0)
		return false;
	if(len2 > len1)
		return true;
	if(len1 > len2)
		return false;
	for(int i = 1;i <= len1;i++)
		if(num[l1+i-1] > num[l2+i-1])
			return false;
		else if(num[l2+i-1] > num[l1+i-1])
			return true;
	return false;
}

inline void dp1(){	//处理到序列第i个数的时候最后第一个数最小的开头下标位置
	for(int i = 1;i <= n;i++){
		f1[i] = 1;
		for(int j = i-1;j >= 1;j--)
			if(bijiao(f1[j],j,j+1,i)){
				f1[i] = j+1;
				break;
			}
	}
}

inline void dp2(){	//处理到序列第i个数的时候开头第一个数最大的末尾下标位置
	f2[f1[n]] = n;
	for(int i = f1[n]-1;i >= 0 && num[i] == 0;i--)
		f2[i] = n;
	for(int i = f1[n]-1;i >= 1;i--)
		for(int j = f1[n];j > i;j--)
			if(bijiao(i,j-1,j,f2[j])){
				f2[i] = j-1;
				break;
			}
}

inline void Print(){
	int p = 1;
	bool flag = false;
	while(p <= n){
		if(flag) putchar(',');
		for(int i = p;i <= f2[p];i++)
			putchar('0'+num[i]);
		p = f2[p]+1;
		flag = true;
	}
	putchar('\n');
}

int main(){
	Init();
	dp1();
	dp2();
	Print();
	return 0;
}