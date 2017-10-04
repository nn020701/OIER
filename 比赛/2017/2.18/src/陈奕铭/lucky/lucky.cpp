#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int INF=999999999;
char s[10010],s2[10010],s3[10010];
int num_s[10];
int ans=INF;
int n,k;
int main(){
	freopen("lucky.in","r",stdin);
	freopen("lucky.out","w",stdout);
	n=read();k=read();
	int q;
	scanf("%s",s);
	s2[n]='\0';
	s3[n]='\0';
	for(int i=0;i<strlen(s);i++)
		num_s[s[i]-'0']++;
	int sum,p;
	for(int z=0;z<=9;z++){
		for(int i=0;i<n;i++)
			s2[i]=s[i];
		q=k;sum=0;
		q-=num_s[z];
		for(int i=1;i<=9;i++){
			if(z+i<=9){
				if(num_s[z+i]>=q){
					sum+=i*q;
					p=q;
					for(int j=0;j<n;j++){
						if(p<=0)
							break;
						if(s2[j]=='0'+z+i){
							s2[j]='0'+z;
							p--;
						}
					}
					break;
				}
				else{
					q-=num_s[z+i];
					sum+=num_s[z+i]*i;
					p=num_s[z+i];
					for(int j=0;j<n;j++){
						if(p<=0)
							break;
						if(s2[j]=='0'+z+i){
							s2[j]='0'+z;
							p--;
						}
					}
				}
			}
			if(z-i>=0){
				if(num_s[z-i]>=q){
					sum+=i*q;
					p=q;
					for(int j=n-1;j>=0;j--){
						if(p<=0)
							break;
						if(s2[j]=='0'+z-i){
							s2[j]='0'+z;
							p--;
						}
					}
					break;
				}
				else{
					q-=num_s[z-i];
					sum+=num_s[z-i]*i;
					p=num_s[z-i];
					for(int j=n-1;j>=0;j--){
						if(p<=0)
							break;
						if(s2[j]=='0'+z-i){
							s2[j]='0'+z;
							p--;
						}
					}
				}
			}
		}
		if(ans>sum||(ans==sum)&&strcmp(s3,s2)>0){
			ans=sum;
			for(int i=0;i<n;i++)
				s3[i]=s2[i];
		}
	}
	printf("%d\n",ans);
	printf("%s\n",s3);
	return 0;
}
