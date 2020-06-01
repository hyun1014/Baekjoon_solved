import sys
from collections import deque

def bfs(a,b):
    q=deque()
    vi=[False]*100001
    q.appendleft(a)
    vi[a]=True
    x=1
    y=0
    cnt=0
    while len(q)!=0:
        cur=q.pop()
        if cur==b:
            print(cnt)
            return
        if cur!=0 and not vi[cur-1]:
            vi[cur-1]=True
            y+=1
            q.appendleft(cur-1)
        if cur!=100000 and not vi[cur+1]:
            vi[cur+1]=True
            y+=1
            q.appendleft(cur+1)
        if cur<=50000 and not vi[cur*2]:
            vi[cur*2]=True
            y+=1
            q.appendleft(cur*2)
        x-=1
        if x==0:
            cnt+=1
            x,y=y,x

n,k=map(int,sys.stdin.readline().strip().split())
bfs(n,k)