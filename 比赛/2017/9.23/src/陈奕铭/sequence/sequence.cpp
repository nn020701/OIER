#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
#define N 300005
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

int a[N],cnt;
int stack[N],top;
int d[N];
int num[N];
set<int> s;
int n,m;

int erfen(int x){
	int l = 1,r = cnt;
	while(l <= r){
		int mid = (l+r)>>1;
		if(d[mid] == x) return mid;
		else if(d[mid] > x) r = mid-1;
		else l = mid+1;
	}
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n = read(); m = read();
	for(int i = 1;i <= n;i++)
		a[i] = d[i] = read();
	sort(d+1,d+n+1);
	cnt = 1;
	for(int i = 2;i <= n;i++)
		if(d[i] != d[i-1])
			d[++cnt] = d[i];
	for(int i = 1;i <= n;i++)
		a[i] = erfen(a[i]);
	int point = 1,after = 1;
//	s.insert(12);
//	s.insert(13);
//	int it = *s.begin();
//	printf("%d\n",it);	
	for(int i = 1;i <= n;i++){
//		printf("# %d %d %d\n",i,point,after);
		if(point == n+1) break;
		for(;after < point+m-top && after < n+1;after++){	//当栈填满时最多的 
			s.insert(a[after]);
			num[a[after]]++;
		}
		int it = *s.begin();
		if(top > 0 && it >= stack[top]){	//如果栈里有数并且栈顶比后面的要小 
			printf("%d ",d[stack[top]]);
//			printf("%d\n",top);
			top--;
		}
		else{					//否则一直压入栈直至这个最小的数 
			while(a[point] != it){
				stack[++top] = a[point];
				if(num[a[point]] == 1)
					s.erase(a[point]);
				num[a[point]]--;
				point++;
			}
			printf("%d ",d[a[point]]);
//			printf("%d\n",top);
			if(num[a[point]] == 1)	//将这个数输出但不入栈 
				s.erase(a[point]);
			num[a[point]]--;
			point++;
		}
	}
//	printf("# %d %d\n",point,after);
	while(top > 0){
		printf("%d ",d[stack[top]]);
		top--;
	}
	puts("");
	return 0;
}
