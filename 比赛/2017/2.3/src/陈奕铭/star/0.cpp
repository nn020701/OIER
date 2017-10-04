#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#define scan(i,j) if(map[i][j]=='1')floodfill(i,j)
using namespace std;
char map[110][110],ansmap[110][110];
int w,h;
double dissum;
double all[30];
char num;
int alpha=0;
int coor[310][2];
int EID=0;
inline bool eq(double a, double b){
    double abss;
    if(a>b)
        abss=a-b;
    else
        abss=b-a;
    if(abss<=0.00001)
        return true;
    else
        return false;
}
inline void floodfill(int x, int y){
    map[x][y]='0';
    coor[++EID][0]=x;
    coor[EID][1]=y;
    scan(x+1,y);
    scan(x+1,y-1);
    scan(x+1,y+1);
    scan(x,y+1);
    scan(x,y-1);
    scan(x-1,y);
    scan(x-1,y-1);
    scan(x-1,y+1);
}
inline double dis(int a, int b){
    return sqrt(((coor[a][0] - coor[b][0])*(coor[a][0] - coor[b][0])) + ((coor[a][1] - coor[b][1])*(coor[a][1] - coor[b][1])));
}
inline void scanff(){
    scanf("%d%d",&w,&h);
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            cin>>map[i][j];
}
inline void print(){
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(ansmap[i][j]<'a'||ansmap[i][j]>'z')
                cout<<"0";
            else
                cout<<ansmap[i][j];
        }
        cout<<endl;
    }
}
inline void solve(){
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            if(map[i][j]=='1'){
                dissum=0;
                EID=0;
                floodfill(i,j);
                for(int k=1;k<=EID;k++)
                    for(int p=k+1;p<=EID;p++)
                        dissum+=dis(p,k);
                bool flag=0;
                for(int k=1;k<=alpha;k++){
                    if(eq(dissum,all[k])){
                        num='a'+k-1;
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    all[++alpha]=dissum;
                    num=alpha+'a'-1;
                }
                for(int k=1;k<=EID;k++)
                    ansmap[coor[k][0]][coor[k][1]]=num;
            }
}
int main(){
	freopen("star.in", "r", stdin);
    freopen("star.out", "w", stdout);
    scanff();
    solve();
    print();
    return 0;
}
