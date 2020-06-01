import sys
from collections import deque
v=[]
q=deque()
dx=[0,-1,0,1]
dy=[-1,0,1,0]
d=[-1,-10000,1,10000]
t=0
cnt=0
def bfs(m,n):
    global t
    global cnt
    a=0
    b=0
    for i in range(1,n+1):
        for j in range(1,m+1):
            if v[i][j]==1:
                a+=1
                q.appendleft(i*10000+j)
    while(len(q)!=0):
        tar=q.pop()
        x=tar//10000
        y=tar%10000
        for i in range(4):
            if v[x+dx[i]][y+dy[i]]==0:
                v[x+dx[i]][y+dy[i]]+=1
                t-=1
                b+=1
                q.appendleft(tar+d[i])
        a-=1
        if a==0:
            cnt+=1
            a,b=b,a
    return
        

m,n=map(int,sys.stdin.readline().strip().split())
v.append([-1]*(m+2))
for _ in range(n):
    li=list(map(int,('-1 '+sys.stdin.readline().strip() + ' -1').split()))
    t+=li.count(0)
    v.append(li)
v.append([-1]*(m+2))
bfs(m,n)
print((cnt-1) if t==0 else -1)