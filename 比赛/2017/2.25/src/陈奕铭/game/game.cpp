#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int a[1000010],Max[1010];
int pos[1000010],block,num_b;
int Min[1010];
int n;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	block=sqrt(n);
	num_b=(n-1)/block+1;
	memset(Min,0x7f,sizeof Min);
	for(int i=1;i<=n;i++){
		a[i]=read();
		pos[i]=(i-1)/block+1;
		if(Max[pos[i]]<a[i])
			Max[pos[i]]=a[i];
		if(Min[pos[i]]>a[i])
			Min[pos[i]]=a[i];
	}
	int mr_Min,mr_Max,q;
	int ml_Min,ml_Max;
	printf("-1\n");
	bool flag_1,flag_2;
	for(int i=2;i<=n-1;i++){
		if(a[i-1]>a[i]||a[i+1]>a[i]){
			printf("-1\n");
			continue;
		}
		ml_Min=a[i-1]; ml_Max=a[i-1];
		mr_Min=a[i+1]; mr_Max=a[i+1];
		flag_1=true;
		flag_2=true;
		for(int j=i-2;j>=(pos[i]-1)*block+1;j--){
			if(a[j]>a[i]){
				flag_1=false;
				break;
			}
			if(ml_Max<a[j]) ml_Max=a[j];
			if(ml_Min>a[j]) ml_Min=a[j];
		}
		if(n<pos[i]*block) q=n;
		else q=pos[i]*block;
		for(int j=i+2;j<=q;j++){
			if(a[j]>a[i]){
				flag_2=false;
				break;
			}
			if(mr_Max<a[j]) mr_Max=a[j];
			if(mr_Min>a[j]) mr_Min=a[j];
		}
		for(int j=pos[i]-1;j>=1;j--){
			if(!flag_1) break;
			if(Max[j]<=a[i]){
				if(ml_Max<Max[j]) ml_Max=Max[j];
				if(ml_Min>Min[j]) ml_Min=Min[j];
				continue;
			}
			for(int z=j*block;z>=(j-1)*block+1;z--){
				if(a[z]>a[i]){
					flag_1=false;
					break;
				}
				if(ml_Max<a[z]) ml_Max=a[z];
				if(ml_Min>a[z]) ml_Min=a[z];
			}
		}
		for(int j=pos[i]+1;j<=num_b;j++){
			if(!flag_2) break;
			if(Max[j]<=a[i]){
				if(mr_Max<Max[j]) mr_Max=Max[j];
				if(mr_Min>Min[j]) mr_Min=Min[j];
				continue;
			}
			if(n<j*block) q=n;
			else q=j*block;
			for(int z=(j-1)*block+1;z<=q;z++){
				if(a[z]>a[i]){
					flag_2=false;
					break;
				}
				if(mr_Max<a[z]) mr_Max=a[z];
				if(mr_Min>a[z]) mr_Min=a[z];
			}
		}
		printf("%d\n",max(mr_Max-ml_Min,ml_Max-mr_Min));
	}
	printf("-1\n");
	return 0;
}
