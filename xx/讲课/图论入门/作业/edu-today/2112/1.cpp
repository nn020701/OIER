#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>	
#include<cstring>
#include<queue>
#include<map>
using namespace std;
#define MAXN 200
#define INF 0xFFFFFFF

int n , star , ed , cnt;
long long  dis[MAXN][MAXN];
map<string , int>m;

long long  min(long long a , long long  b){
   return a < b ? a : b;
}

void init(){
   cnt = 0;
   m.clear();
   for(int i = 1 ; i < MAXN ; i++){
      for(int j = 1 ; j < MAXN ; j++){
          if(i == j)
            dis[i][j] = 0;
          else
            dis[i][j] = INF;
      }
   }
}

void floyd(){
   for(int k = 1 ; k <= cnt ; k++){
      for(int i = 1 ; i <= cnt ; i++){
         for(int j = 1 ; j <= cnt ; j++)
            dis[i][j] = min(dis[i][k]+dis[k][j] , dis[i][j]);
      }
   }
}

void input(){
   int a , b , v;
   char str1[MAXN] , str2[MAXN];
   init();
   scanf("%s%s" , str1 , str2);
       
   a = m[str1];
   if(!a)
      m[str1] = a = ++cnt;
   b = m[str2];
   if(!b)
      m[str2] = b = ++cnt;
   star = a;
   ed = b;
   
   for(int i = 0 ; i < n ; i++){
        scanf("%s%s%d" , str1 , str2 , &v);
        a = m[str1];
        b = m[str2];
        if(!a)
           m[str1] = a = ++cnt;
        if(!b)
           m[str2] = b = ++cnt;
        if(dis[a][b] > v)
           dis[a][b] = dis[b][a] = v;
    }
}

int main(){
    while(scanf("%d" , &n) && n != -1){
          input();
          floyd();
          if(dis[star][ed] != INF)
             printf("%d\n" , dis[star][ed]);
          else
             printf("-1\n");
    }
    return 0;
}
