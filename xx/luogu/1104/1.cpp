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

struct node{
	string s;
	int year,moth,day;
	int num;
}a[105];
int n;

bool cmp(node a,node b){
	if(a.year == b.year){
		if(a.moth == b.moth){
			if(a.day == b.day)
				return a.num > b.num;
			return a.day < b.day;
		}
		return a.moth < b.moth;
	}
	return a.year < b.year;
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++){
		cin>>a[i].s>>a[i].year>>a[i].moth>>a[i].day;
		a[i].num = i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++)
		cout<<a[i].s<<endl;
	return 0;
}
