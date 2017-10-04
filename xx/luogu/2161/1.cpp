#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200005
#define M 600005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int cflag,lflag,rflag;
	int l,r;
}tree[M];
struct calss{
	int l,r;
}cals[N];
int cnt;
int ans,Num;
int n;

int build(int num,int l,int r){
	tree[num].l = l;
	tree[num].r = r;
	tree[num].cflag = tree[num].lflag = tree[num].rflag = 0;
	if(l == r) return 0;
	int mid = (l+r)>>1;
	build(num<<1,l,mid);
	build(num<<1|1,mid+1,r);
	return 0;
}


// void pushdown(int num){
// 	int l = num<<1,r = num<<1|1;
// 	if(tree[num].flag){
// 		tree[l].flag = tree[r].flag = true;
// 		tree[l].color = tree[r].color = tree[num].color;
// 		tree[num].flag = false;
// 	}
// }

// void update(int num){
// 	int l = num<<1,r = num<<1|1;
// 	if(tree[l].color == tree[r].color)
// 		tree[num].color = tree[l].color;
// 	else tree[num].color = 0;
// 	tree[num].flag = false;
// }

int Delete(int num,int x,int y){
	int l = tree[num].l;
	int r = tree[num].r;
	if(x <= l && r <= y){
		tree[num].cflag = tree[num].lflag = tree[num].rflag = 0;
		return 0;
	}
	int mid = (l+r)>>1;
	// pushdown(num);
	if(x <= mid)
		Delete(num<<1,x,y);
	if(y > mid)
		Delete(num<<1|1,x,y);
	if(tree[num].lflag == 0 && tree[num].rflag == 0)
		return 0;
	return 1;
	// update(num);
}

int query(int num,int x,int y,int color){
	int l = tree[num].l;
	int r = tree[num].r;
	if(tree[num].cflag != 0){
		Delete(1,cals[tree[num].cflag].l,cals[tree[num].cflag].r);
		Num++;
	}
	int mid = (l+r)>>1;
	if(x <= l && r <= y){
		if(tree[num].lflag != 0)
			query(num<<1,x,y,0);
		if(tree[num].rflag != 0)
			query(num<<1|1,x,y,0);
		tree[num].lflag = tree[num].rflag = 0;
		tree[num].cflag = color;
		return 0;
	}
	// pushdown(num);
	if(x <= mid){
		query(num<<1,x,y,color);
		tree[num].lflag = 1;
	}
	if(y > mid){
		query(num<<1|1,x,y,color);
		tree[num].rflag = 1;
	}
	return 0;
	// update(num);
}


int main(){
	n = read();
	build(1,1,100000);
	for(int i = 1;i <= n;i++){
		char s[10];
		scanf("%s",s);
		// puts("1");
		if(s[0] == 'A'){
			int x,y;
			scanf("%d %d",&x,&y);
			cals[++cnt].l = x;
			cals[cnt].r = y;
			Num = 0;
			query(1,x,y,cnt);
			ans -= Num-1;
			printf("%d\n",Num);
		}
		else{
			printf("%d\n",ans);
		}
	}
	return 0;
}

// #include<set>
// #include<cstdio>
// #include<cstring>
// #include<iostream>
// #include<algorithm>
// using namespace std;
// #define ll long long
// #define N 200005
// inline int read(){
// 	int x=0,f=1;char ch=getchar();
// 	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
// 	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
// 	return x*f;
// }

// struct node{
// 	int l,r;
// 	friend bool operator <(node a,node b){
// 		return a.r < b.r || (a.r == b.r && a.l < b.l);
// 	}
// };
// int n;
// set<node> s;

// int main(){
// 	n = read();
// 	while(n--){
// 		char c[10];
// 		scanf("%s",c);
// 		if(c[0] == 'A'){
// 			int x,y;
// 			scanf("%d %d",&x,&y);
// 			int num = 0;
// 			set<node> :: iterator it;
// 			it = s.lower_bound((node){0,x});
// 			while(it != s.end() && y >= it -> l){
// 				s.erase(it);
// 				num++;
// 				it = s.lower_bound((node){0,x});
// 			}
// 			s.insert((node){x,y});
// 			printf("%d\n", num);
// 		}
// 		else printf("%d\n", s.size());
// 	}
// 	return 0;
// }