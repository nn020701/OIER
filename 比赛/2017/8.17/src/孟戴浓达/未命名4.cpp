#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<fstream>
using namespace std;
//ifstream fin("heap.in");
//ofstream fout("heap.out");
const long long mod=100000000007;
struct matrix{
	int mat[5][5];
};
matrix mul(matrix a,matrix b){
	matrix c;
	memset(c.mat,0,sizeof(c.mat));
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			for(int k=1;k<=2;k++){
				c.mat[i][j]=(a.mat[i][k]*b.mat[k][j])%mod;
			}
		}
	}
	return c;
}
matrix qpow(matrix x,int y){
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
	if(b==1){
		return a;
	}
	long long fanhui=qpow(a,b/2);
	fanhui=fanhui*fanhui%mod;
	if(b%2==1){
		fanhui=fanhui*a%mod;
	}
	return fanhui;
}
string s;
long long k;
int main(){
	cin>>s>>k;
	int len=s.length();
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
	cout<<gong_ans<<" "<<gong_tot<<endl;
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
1000

out:
502025683

in:
*L*P*R*L*P*R
1

out:

*/
