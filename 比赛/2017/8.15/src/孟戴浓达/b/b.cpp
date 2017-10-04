#include<algorithm>
#include<cmath>
#include<cstring>
#include<fstream>
using namespace std;
ifstream fin("b.in");
ofstream fout("b.out");
int num[1003][1003];
int tong[13];
int sum[1003][1003][13];
int n,m;
int main(){
	fin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			fin>>num[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<=9;k++){
				sum[i][j][k]+=sum[i-1][j][k]+sum[i][j-1][k];
				sum[i][j][k]-=sum[i-1][j-1][k];
				sum[i][j][k]+=(num[i][j]==k);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int i1=1;i1<=i;i1++){
				for(int j1=1;j1<=j;j1++){
					for(int x=0;x<=9;x++){
						tong[x]=sum[i][j][x];
						tong[x]-=sum[i1-1][j1][x];
						tong[x]-=sum[i1][j1-1][x];
						tong[x]+=sum[i1-1][j1-1][x];
					}
					bool yes1=false,yes2=false;
					for(int x=0;x<=9;x++){
						if(tong[x]!=0&&x>=1){
							yes2=true;
						}
						if(tong[x]%2!=0){
							if(yes1==true){
								yes1=false;
								break;
							}
							yes1=true;
						}
					}
					if(yes1&&yes2){
						ans=max((i-i1+1)*(j-j1+1),ans);
					}
				}
			}
		}
	}
	fout<<ans<<endl;
	return 0;
}
/*

in:
3 3
1 1 1
1 0 1
1 1 1

out:
9

*/
