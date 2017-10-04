#coding:utf-8
#Å£¶Ùµü´ú·¨
import sys
def power(x,y):  #x^y
	ans=1
	for i in range(y):ans*=x
	return ans

m=int(input())
n=int(input())
if n==0:
	print 0
	sys.exit()
_n=n;len=0
while _n>0:
	_n/=10;len+=1
base=300
wei=len/m
now=len%m
while (now+m<=base)and(wei>0):
	now+=m;wei-=1
div=1
for i in range(wei*m):div*=10
_n=n/div
#print "len=",len,"wei=",wei,"now=",now
#print _n
_f=float(_n)**(1.0/m)
#print _f
x=int(_f)
for i in range(wei):x*=10
time=0
while True:
	time+=1
	_x=x
	x=x+x*(n-power(x,m))/(n*m)
	if x==_x:break
#print "time=",time
while pow(x+1,m)<=n:
	x=x+1
print x
#os.system("pause")


