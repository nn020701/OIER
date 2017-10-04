#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
ifstream fin("heap.in");
ofstream fout("heap.out");
const long long mod=1000000007;
struct matrix{
	int mat[5][5];
};
matrix mul(matrix a,matrix b){
	matrix c;
	memset(c.mat,0,sizeof(c.mat));
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			for(int k=1;k<=2;k++){
				c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j]%mod+mod)%mod;
			}
		}
	}
	return c;
}
matrix qpow(matrix x,long long y){
	if(y==1){
		return x;
	}
	matrix fanhui=qpow(x,y/2);
	fanhui=mul(fanhui,fanhui);
	if(y%2==1){
		fanhui=mul(fanhui,x);
	}
	return fanhui;
}
long long qpow(long long a,long long b){
	if(b==0){
		return 1%mod;
	}
	if(b==1){
		return (a%mod+mod)%mod;
	}
	long long fanhui=qpow(a,b/2);
	fanhui=((fanhui*fanhui)%mod+mod)%mod;
	if(b%2==1){
		fanhui=((fanhui*a%mod)+mod)%mod;
	}
	return fanhui;
}
string s;
long long k;
int main(){
	fin>>s>>k;
	int len=s.length();
	if(k==1){
		long long ans=1,tot=1;
		for(int i=0;i<=len-1;i++){
			if(s[i]=='*'){
				ans=(ans*5%mod+tot)%mod;
				tot*=3;
			}else if(s[i]=='L'){
				ans=(ans*2)%mod;
			}else{
				ans=(ans*2%mod+tot)%mod;
			}
		}
		fout<<ans<<endl;
		return 0;
	}
	long long ans=1,tot=1;
	long long gong_tot=0,gong_ans=1;
	for(int i=0;i<=len-1;i++){
		if(s[i]=='*'){
			gong_tot=gong_tot*5+tot;
			gong_ans=gong_ans*5;
			ans=(ans*5%mod+tot)%mod;
			tot*=3;
		}else if(s[i]=='L'){
			gong_tot=gong_tot*2;
			gong_ans=gong_ans*2;
			ans=(ans*2)%mod;
		}else{
			gong_ans=gong_ans*2;
			gong_tot=gong_tot*2+tot;
			ans=(ans*2%mod+tot)%mod;
		}
	}
	long long inv=qpow(gong_ans,mod-2);
	long long chu=qpow(gong_ans,k-1);
	/*
	matrix a,b;
	memset(a.mat,0,sizeof(a.mat));
	memset(b.mat,0,sizeof(b.mat));
	a.mat[1][1]=chu%mod;
	a.mat[2][1]=0;
	b.mat[1][1]=(inv*tot)%mod;   b.mat[1][2]=0;
	b.mat[2][1]=1;               b.mat[2][2]=1;
	cout<<mul(b,b)<<endl;
	cout<<b.mat[1][1]<<" "<<b.mat[1][2]<<endl<<b.mat[2][1]<<" "<<b.mat[2][2]<<endl;
	a=mul(a,mul(a,b));
	cout<<a.mat[1][1]<<" "<<a.mat[1][2]<<endl<<a.mat[2][1]<<" "<<a.mat[2][2]<<endl;
	*/
	long long p=(inv*tot+mod)%mod;
	long long xx=qpow(gong_ans,k);
	long long yy=((gong_tot%mod*chu%mod)%mod*(qpow(1-p,mod-2)+mod)%mod*(1-qpow(p,k)+mod)%mod)%mod;
	fout<<(xx+yy+mod)%mod<<endl;
	return 0;
}
/*

in:
L*R
1

out:
25

in:
*L*P*R
7
*L*P*R
1000
out:
502025683

in:
*L*P*R*L*P*R*L*P*R*L*P*R*L*P*R*L*P*R*L*P*R
1

out:

*/
