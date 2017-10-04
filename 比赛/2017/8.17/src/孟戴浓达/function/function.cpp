#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const long long mod=1000000007;
ifstream fin("function.in");
ofstream fout("function.out");
int prime[1000003];
bool vis[1000003];
int phi[1000003];
inline void pri(){
    int cnt=0;
    for(int i=2;i<=1000000;i++){
        if(!vis[i]){
            prime[cnt++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<cnt&&i*prime[j]<=1000000;j++){
            long long k=i*prime[j];
            vis[k]=1;
            if(i%prime[j]==0){
                phi[k]=phi[i]*prime[j];
                break;
			}else{
            	phi[k]=phi[i]*(prime[j]-1);
			}
        }
    }
    phi[1]=1;
}
long long euler(long long n){
     long long res=n,a=n;
     for(long long i=2;i*i<=a;i++){
         if(a%i==0){
             res=res/i*(i-1);
             while(a%i==0){
             	a/=i;
			 }
         }
     }
     if(a>1){
     	res=res/a*(a-1);
	 }
     return res;
}
long long euler2(long long x){
	return phi[x];
}
long long solve2(long long n,long long k){
	if(k==0){
		return n%mod;
	}else if(k%2==1){
		return euler2(solve2(n,k-1)%mod)%mod;
	}else{
		return solve2(n,k-1)%mod;
	}
}
long long solve(long long n,long long k){
	if(k==0){
		return n%mod;
	}else if(k%2==1){
		return euler(solve(n,k-1)%mod)%mod;
	}else{
		return solve(n,k-1)%mod;
	}
}
int main(){
	int T;
	pri();
	fin>>T;
	while(T--){
		long long n,k;
		fin>>n>>k;
		long long x=n;
		int tot=0;
		fout<<solve2(n,k)<<endl;
		/*
		while(x!=1){
			x=euler(x);
			tot++;
		}
		if(k%2==1){
			if((k+1)/2>=tot){
				cout<<1<<endl;
			}
		}else{
			if(k/2>=tot){
				cout<<1<<endl;
			}
		}
		cout<<solve(n,k)%mod<<endl;
		*/
	}
	return 0;
}
/*

in:
3
15 2
233 3
23333333333 3

out:
8
112
271986803

*/
