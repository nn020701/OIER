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
bool flag[N];			//����Ǹ������ܷ����� 
int f[N];				//��������ɸ�������С�������� 
queue<node> q;
int n;
int s[10],len;

void bfs(){							//bfs�����п��Եõ��ÿ����� 
	while(!q.empty()){
		node a = q.front(); q.pop();
		int b;
		len = 0;
		while(a.a){					//������ת��Ϊ���� 
			s[++len] = a.a%10;
			a.a /= 10;
		}
		if(len == 1) continue;		//��len����1��ʱ�����ٽ����κ�һ������� 
		//ɾ��һλ���Ĳ��� 
		for(int i = 1;i <= len;i++){		//����ö��ɾ����һλ�� 
			b = 0;
			for(int j = len;j >= 1;j--)		//���黹ԭ�����֣�����ͬ�� 
				if(j != i)
					b = b*10+s[j];
			if(flag[b]) continue;			//�ж��Ƿ���ڹ���û�еĻ��Ͳ��� 
			flag[b] = true;
			f[b] = a.ans+1;
			node p;
			p.a = b; p.ans = a.ans+1;
			q.push(p);
		}
		//������λ���Ĳ��� 
		for(int i = 1;i <= len;i++)
			for(int j = i+1;j <= len;j++){		//i��j����ö�ٽ�������λ���� 
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
		//���һλ���Ĳ��� 
		if(len == n) continue;			//���ܳ���ԭ���еĳ���  
		for(int i = 1;i < len;i++){		//ö��������λ�м���� 
			for(int j = s[i]-1;j > s[i+1];j--){		//ö����ӵ����� 
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
