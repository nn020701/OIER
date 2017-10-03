#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 100005
#define M 10
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int a,ans;
};
bool flag[N];			//存的是该数字能否生成 
int f[N];				//存的是生成该数字最小操作次数 
queue<node> q;
int n;
int s[10],len;

void bfs(){							//bfs求所有可以得到得可能性 
	while(!q.empty()){
		node a = q.front(); q.pop();
		int b;
		len = 0;
		while(a.a){					//将数字转化为数组 
			s[++len] = a.a%10;
			a.a /= 10;
		}
		if(len == 1) continue;		//当len等于1的时候不能再进行任何一项操作了 
		//删除一位数的操作 
		for(int i = 1;i <= len;i++){		//这是枚举删除哪一位数 
			b = 0;
			for(int j = len;j >= 1;j--)		//数组还原成数字，下面同样 
				if(j != i)
					b = b*10+s[j];
			if(flag[b]) continue;			//判断是否存在过，没有的话就插入 
			flag[b] = true;
			f[b] = a.ans+1;
			node p;
			p.a = b; p.ans = a.ans+1;
			q.push(p);
		}
		//交换两位数的操作 
		for(int i = 1;i <= len;i++)
			for(int j = i+1;j <= len;j++){		//i和j是在枚举交换哪两位数字 
				b = 0;
				swap(s[i],s[j]);
				for(int k = len;k >= 1;k--)
					b = b*10+s[k];
				swap(s[i],s[j]);
				if(flag[b]) continue;
				flag[b] = true;
				f[b] = a.ans+1;
				node p;
				p.a = b; p.ans = a.ans+1;
				q.push(p);
			}
		//添加一位数的操作 
		if(len == n) continue;			//不能超过原序列的长度  
		for(int i = 1;i < len;i++){		//枚举在哪两位中间添加 
			for(int j = s[i]-1;j > s[i+1];j--){		//枚举添加的数字 
				b = 0;
				for(int k = len;k > i;k--)
					b = b*10+s[k];
				b = b*10+j;
				for(int k = i;k >= 1;k--)
					b = b*10+s[k];
				if(flag[b]) continue;
				flag[b] = true;
				f[b] = a.ans+1;
				node p;
				p.a = b; p.ans = a.ans+1;
				q.push(p);
			}
		}
	}
}

int main(){
	int a = read();
	flag[a] = true;
	node p; p.a = a; p.ans = 0;
	q.push(p);
	while(a){
		s[++len] = a%10;
		a /= 10;
	}
	n = len;
	bfs();
	int m = read();
	for(int i = 1;i <= m;i++){
		int a = read();
		if(!flag[a]) printf("-1\n");
		else printf("%d\n",f[a]);
	}
	return 0;
}
