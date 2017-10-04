#include<algorithm>
#include<cmath>
#include<cstring>
#include<fstream>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
int n,W;
long long num[1003][1003];
long long f1[1003][1003],f2[1003][1003];
inline void init(){
	for(int i=1;i<=n;i++){
		f1[i][1]=num[i][1];
	}
	for(int i=1;i<=n;i++){
		f1[1][i]=num[1][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f1[i][j]=num[i][j]+f1[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		f2[i][n]=num[i][n];
	}
	for(int i=1;i<=n;i++){
		f2[1][i]=num[1][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f2[i][j]=num[i][j]+f2[i-1][j+1];
		}
	}
}
int main(){
	fin>>n>>W;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			fin>>num[i][j];
		}
	}
	init();
	for(int k=n;k>=1;k--){
		for(int i=k;i<=n;i++){
			for(int j=k;j<=n;j++){
				if(k%2==1){
					int s=(f1[i][j]-f1[i-k][j-k])+(f2[i][j-k]-f2[i-k][j])+num[i-k/2][j-k/2];
					if(s<=W){
						fout<<k<<endl;
						return 0;
					}
				}else{
					int s=(f1[i][j]-f1[i-k][j-k])+(f2[i][j-k]-f2[i-k][j]);
					if(s<=W){
						fout<<k<<endl;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
/*

in:
3 5
1 1 1
1 1 1
1 1 1

out:
3

*/
