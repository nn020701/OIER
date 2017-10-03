#include<cstdio>
#include<iomanip>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

long double x[N],y[N],w[N],t;
bool flag;
int n;

bool check(long double v){
	t = 0;
	for(int i = 1;i <= n;i++){
		t = t+w[i]/v;
		if(t <= y[i]){
			t = max(t,x[i]);
			flag = false;
		}
		else{
			flag = true;
			break;
		}
	}
	if(flag) return false;
	else return true;
}

void erfen(){
	long double v;
	long double l = 0.000001,r = 2000000000;
	while(r - l > 0.000001){
		v = (l+r)/2;
		if(check(v)) r = v;
		else l = v;
	}
	cout<<fixed<<setprecision(2)<<l<<endl;
	return;
}

int main(){
	scanf("%d\n",&n);
	for(int i = 1;i <= n;i++){
		x[i] = read(); y[i] = read(); w[i] = read();
	}
	erfen();
	return 0;
}
