#include <cstdio>
using namespace std;
int main(){
	double res=1;
	for(int i=1000000-500;i<=1000000;i++)
		res*=i/1000000.0;
	printf("%f",res);
}