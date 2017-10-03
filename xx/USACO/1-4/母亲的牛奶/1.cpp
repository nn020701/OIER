#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int a[4];	
int fg[22][22];
int note[22];
void search(int x,int y,int z){
	if(fg[x][y]==1) return ;
	fg[x][y]=1;
	if(x==0) note[z]=1;
	int i,j;
	int ji[4]={0};
	ji[1]=x;
	ji[2]=y;
	ji[3]=z;
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			if(i!=j)
				if(ji[i]!=0&&ji[j]!=a[j]){
					if(ji[i]>a[j]-ji[j]){
						int t1=ji[i],t2=ji[j];
						ji[i]-=a[j]-ji[j];
						ji[j]=a[j];
						search(ji[1],ji[2],ji[3]);
						ji[i]=t1;
						ji[j]=t2;
					}
					if(ji[i]<=a[j]-ji[j]){
						int t1=ji[i],t2=ji[j];
						ji[j]+=ji[i];
						ji[i]=0;
						search(ji[1],ji[2],ji[3]);
						ji[i]=t1;
						ji[j]=t2;
					}
				}
	return;
}
int main(){
	int i,j;
	a[1]=read(); a[2]=read();a[3]=read();
	search(0,0,a[3]);
	for(i=0;i<=a[3]-1;i++)
		if(note[i]==1)
			cout<<i<<' ';
	cout<<a[3]<<endl;
	return 0;
}
