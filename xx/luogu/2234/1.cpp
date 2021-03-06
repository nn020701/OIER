#include<iostream>
#include<cstdio>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
void writeln(int x){
	write(x);
	puts("");
}

const int inf=1000000000,N=100005;
int ans,n,t1,t2,rt,size;
int tr[N][2],fa[N],num[N];

void rotate(int x,int &k){
	int y=fa[x],z=fa[y],l,r;
	if(tr[y][0]==x) l=0;
	else l=1;		r=l^1;
	if(y==k) k=x;
	else{
		if(tr[z][0]==y) tr[z][0]=x;
		else 			tr[z][1]=x;
	}
	fa[x]=z; fa[y]=x; fa[tr[x][r]]=y;
	tr[y][l]=tr[x][r]; tr[x][r]=y;
}

void splay(int x,int &k){
	int y,z;
	while(x!=k){
		y=fa[x]; z=fa[y];
		if(y!=k){
			if((tr[y][0]==x)^(tr[z][0]==y))
				 rotate(x,k);
			else rotate(y,k);
		}
		rotate(x,k);
	}
}

void ins(int &k,int x,int last){
	if(k==0){
		size++; k=size;
		num[k]=x; fa[k]=last;
		splay(k,rt); return;
	}
	if(x<num[k]) ins(tr[k][0],x,k);
	else ins(tr[k][1],x,k);
}

void ask_before(int k,int x){
	if(k==0) return;
	if(num[k]<=x){
		t1=num[k];
		ask_before(tr[k][1],x);
	}
	else ask_before(tr[k][0],x);
}

void ask_after(int k,int x){
	if(k==0) return;
	if(num[k]>=x){
		t2=num[k];
		ask_after(tr[k][0],x);
	}
	else ask_after(tr[k][1],x);
}

int main(){
	n = read();
	for(int i=1;i<=n;i++){
		int x = read();
		t1=-inf; t2=inf;
		ask_before(rt,x);
		ask_after(rt,x);
		if(i!=1) ans+=min(x-t1,t2-x);
		else 	 ans+=x;
		ins(rt,x,0);
	}
	printf("%d\n",ans);
	return 0;
}
