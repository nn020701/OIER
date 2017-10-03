#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int n,m;
int f[105][1030][1030];
int mp[105];
int zhuan[1030],cnt,num[1030];

int main(){
	n = read(); m = read();
	for(int i = 1;i <= n;i++){
		char s[15];
		scanf("%s",s+1);
		for(int j = 1;j <= m;j++){
			mp[i] <<= 1;
			if(s[j] == 'P') mp[i] |= 1;
		}
	}

	for(int i = 0;i < (1<<m);i++){
		if(!((i<<1)&i) && !((i<<2)&i)){
			zhuan[++cnt] = i;
			int j = i;
			while(j){
				if(j&1) num[cnt]++;
				j >>= 1;
			}
		}
	}
	
	for(int i = 1;i <= cnt;i++){
		if((zhuan[i]&mp[1]) == zhuan[i])
			f[1][1][i] = num[i];
	}
	
	for(int i = 1;i <= cnt;i++){
		if((zhuan[i]&mp[2]) == zhuan[i])
			for(int j = 1;j <= cnt;j++)
				if((zhuan[j]&mp[1]) == zhuan[j])
					if(!(zhuan[i]&zhuan[j]))
						f[2][j][i] = f[1][1][j]+num[i];
	}
	for(int k = 3;k <= n;k++)
		for(int i = 1;i <= cnt;i++)
			if((zhuan[i]&mp[k]) == zhuan[i])
				for(int j = 1;j <= cnt;j++)
					if((zhuan[j]&mp[k-1]) == zhuan[j])
						if(!(zhuan[i]&zhuan[j]))
							for(int z = 1;z <= cnt;z++)
								if((zhuan[z]&mp[k-2]) == zhuan[z])
									if(!(zhuan[i]&zhuan[z]) && !(zhuan[j]&zhuan[z]))
										f[k][j][i] = max(f[k][j][i],f[k-1][z][j]+num[i]);
	int ans = 0;
	for(int i = 1;i <= cnt;i++)
		for(int j = 1;j <= cnt;j++)
			ans = max(ans,f[n][i][j]);
	printf("%d\n",ans);
	return 0;
}