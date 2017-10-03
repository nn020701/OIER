#include<iostream>
#include<algorithm>
using namespace std;
#define fin cin
#define fout cout
int len,n,m=0;
int a[120002];
int yn[125002];
int xlen=0;
 
struct A {
	int first;
	int difference2;
} x[125002];
 
int my_cmp(const A &x1,const A &x2) {
	if(x1.difference2<x2.difference2) return 1;
	if(x1.first<x2.first) return 1;
	return 0;
}
 
int main() {
	int i,j,k;
	fin>>len>>n;
	for(i=0; i<=n; i++)
		for(j=i; j<=n; j++)
			yn[i*i+j*j]=1;
	int biggest=n*n+n*n;
	for(i=0; i<=biggest; i++)
		if(yn[i])
			a[++m]=i;
	int difference=0;
	for(i=1; i<=m; i++)
		for(j=i+1; j<=m; j++){
			difference=a[j]-a[i];
			if (a[i]+(len-1)*difference>a[m])
				break;
			for(k=2; k<len; k++)
				if(yn[a[i]+k*difference]==0)
					break;
			if(k==len) {
				x[++xlen].first=a[i];
				x[xlen].difference2=difference;
			}
		}
	sort(x+1,x+xlen+1,my_cmp);
	for(i=1; i<=xlen; i++)
		fout<<x[i].first<<' '<<x[i].difference2<<endl;
	if(xlen==0)fout<<"NONE"<<endl;
	return 0;
}
