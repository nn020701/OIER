#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
bool vis[10][10];
bool flag[11];
int map[10][10];
int step[10][5];
int count[11];
int n,N;

int del( ){//������һ���ƶ��ܹ���ȥ����

	memset( vis,1,sizeof vis );
	int res=0;
	int l,r,u,d,x,y,t;
	bool cs=0;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=7;j++)
			if( map[ i ][ j ] )
				if( ( j>=2	&& map[ i ][ j-1 ] ) || j==1 ){//Ѱ�����Ŀ���������������Ŀ�
					l=r=i;
					u=d=j;
					while( l>=2 && map[ l-1 ][ j ]==map[ i ][ j ] ) 
						l--;
					while(r<4 && map[ r+1 ][ j ]==map[ i ][ j ] ) 
						r++;
					while( d>=2 && map[ i ][ d-1 ]==map[ i ][ j ] ) 
						d--;
					while( u<=6 && map[ i ][ u+1 ]==map[ i ][ j ] ) 
						u++; 
					if( r-l>=2 )//��ʾ�᷽���Ͽ�����������
						for(int k=l;k<=r;k++)
							vis[ k ][ j ]=0;
					if( u-d>=2 )//��ʾ�������Ͽ�����������
						for(int k=d;k<=u;k++)
							vis[ i ][ k ]=0;
				}
	for(int i=1;i<=5;i++)
		for(int j=1;j<=7;j++)
			if( !vis[ i ][ j ] ){//��������
				res++;
				map[ i ][ j ]=0;
			}
	for(int i=1,j;i<=5;i++){//��ÿһ���Ƿ��п�����
		for(j=1;j<=7;j++)
			if( !map[ i ][ j ] )
				break;
		x=j;//�ҵ���һ���տ�
		for( ;j<=7;j++ )
			if( map[ i ][ j ] )
				break;
		if( j==8 )//���һֱ�������ǿտ飬��û�п���Ե����������Բ��ù���
			continue;
		y=j-1;//�ҵ��տ鷶Χ��ĩ��
		t=0;
		for( j=x;j<=7;j++ ){//���ŵĿ������
			t++;
			if( !map[ i ][ y+t ] || map[ i ][ j ]) 
				break;
			map[ i ][ j ]=map[ i ][ y+t ];
			map[ i ][ y+t ]=0;
			cs=1;
		}
	}
	if( cs )//����е���ȥ��
		res+=del( );//�����ŵĿ����ȥ����ܻ����Լ�����������������һ��del
	return res;
}

bool judge( ){
	memset( count,0x0,sizeof count );
	for(int i=1;i<=5;i++)
		for(int j=1;j<=7;j++)
			count[ map[ i ][ j ] ]++;
	for(int i=1;i<=N;i++)
		if( count[ i ]>=1 && count[ i ]<=2 )
			return 0;
	return 1;
}

void dfs(int num,int tot){
	if( !judge( ) )
		return ;
	if( num>=n+1 ){
		if( !tot ){//��Ϊ��dfsʱ�Ϳ��ǵ�������˳�����������ѵ��ıض������ȼ�����
//			cout<<"�������� �� "<<zzl<<endl;
			for(int i=1;i<=n;i++)
				printf("%d %d %d\n",step[ i ][ 1 ]-1,step[ i ][ 2 ]-1,step[ i ][ 3 ] );
			exit(0);
		}
		return ;
	}
	int x,y;
	int temp[10][10],p,q;
	bool cs;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=7;j++)
			temp[ i ][ j ]=map[ i ][ j ];
	for(int i=1;i<=5;i++)
		for(int j=1;j<=7;j++){
			if( map[ i ][ j ] ){
				cs=1;
				if( i<=4 &&map[ i ][ j ]!=map[ i+1 ][ j ] ){//��֦��1��
					swap( map[ i ][ j ],map[ i+1 ][ j ] );
					step[ num ][ 1 ]=i;
					step[ num ][ 2 ]=j;
					step[ num ][ 3 ]=1;
					p=tot-del();
					dfs( num+1,p );
					cs=0;
				}
				if( !cs ){
					cs=1;
					for(p=1;p<=5;p++)
						for(q=1;q<=7;q++)
							map[ p ][ q ]=temp[ p ][ q ];
				}
				if( i>=2 && !map[ i-1 ][ j ] ){//��֦��2��	
					swap( map[ i ][ j ],map[ i-1 ][ j ] );
					step[ num ][ 1 ]=i;
					step[ num ][ 2 ]=j;
					step[ num ][ 3 ]=-1;
					p=tot-del();
					dfs( num+1,p );
					cs=0;
				}
				if( !cs )
					for(p=1;p<=5;p++)
						for(q=1;q<=7;q++)
							map[ p ][ q ]=temp[ p ][ q ];
			}
		}
}

int main(){
	int x,y=0;
	scanf("%d",&n);
	for(int i=1,j;i<=5;i++){
		j=0;
		scanf("%d",&x);
		while( x ){
			map[ i ][ ++j ]=x;
			if( !flag[ x ] ){
				flag[ x ]=1;
				N++;
			}
			y++;
			scanf("%d",&x);
		}
	}
	dfs( 1,y );
	cout<<-1<<endl;
	return 0;
}
