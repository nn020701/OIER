#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int f[100010];
int a[100010];
int k=1,ans,n;
int erfen(int l,int r,int q){
	int ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(f[mid]<=a[q]){
			l=mid+1;
			ans=mid;
		}
		else
			r=mid-1;
	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	f[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]<f[k]){
			int q=erfen(1,k,i);
			f[q]=a[i];
			k=q;
		}
		else{
			f[++k]=a[i];
			ans=max(ans,k);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
