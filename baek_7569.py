import sys
from collections import deque
v=[]
q=deque()
dx=[0,-1,0,1,0,0]
dy=[-1,0,1,0,0,0]
dz=[0,0,0,0,1,-1]
d=[-1,-1000,1,1000,1000000,-1000000]
t=0
cnt=0

def bfs(m,n,h):
    a=0
    b=0
    global t
    global cnt
    for k in range(1,h+1):
        for i in range(1,n+1):
            for j in range(1,m+1):
                if v[k][i][j]==1:
                    q.appendleft(k*1000000+i*1000+j)
                    a+=1
    while(len(q)!=0):
        cur=q.pop()
        z=cur//1000000
        x=(cur%1000000)//1000
        y=cur%1000
        for i in range(6):
            if v[z+dz[i]][x+dx[i]][y+dy[i]]==0:
                v[z+dz[i]][x+dx[i]][y+dy[i]]+=1
                t-=1
                q.appendleft(cur+d[i])
                b+=1
        a-=1
        if a==0:
            cnt+=1
            a,b=b,a


m,n,h=map(int,sys.stdin.readline().strip().split())
v.append([[-1]*(m+2) for _ in range(n+2)])
for k in range(1,h+1): 
    li=[[-1]*(m+2)]
    for i in range(1,n+1):
        li.append(list(map(int, ("-1 " + sys.stdin.readline().strip() + " -1").split())))
    li.append([-1]*(m+2))
    v.append(li)
v.append([[-1]*(m+2) for _ in range(n+2)])
for k in range(1,h+1):
    for i in range(1,n+1):
        for j in range(1,m+1):
            if v[k][i][j]==0:
                t+=1
bfs(m,n,h)
if(t==0):
    print(cnt-1)
else:
    print(-1)
