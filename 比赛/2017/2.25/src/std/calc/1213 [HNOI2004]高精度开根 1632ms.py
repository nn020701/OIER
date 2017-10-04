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
x=1
len/=m
if len<1:len=1
for i in range(len-1):x*=10
time=0
while True:
	time+=1
	_x=x
	x=x+x*(n-power(x,m))/(n*m)
	if x==_x:break
while pow(x+1,m)<=n:
	x=x+1
print x
#os.system("pause")


