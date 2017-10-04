#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
bool ntprime[1000002];
int main(){
	for(int i=2;i<=1000000;i++)
		if (!ntprime[i])
			for(int j=i*2;j<=1000000;j+=i)
				ntprime[j]=true;
	mt19937 w(GetTickCount());
	for(int i=0;i<10;i++){
		while(true){
			int x=w()%100001+900000;
			if (!ntprime[x]){
				printf("%d ",x);
				break;
			}
		}
	}
}