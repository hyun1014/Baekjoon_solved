import sys
from collections import deque
ch=[]
vi=[[False]*102 for _ in range(102)]
dx=[0,-1,0,1]
dy=[-1,0,1,0]
d=[-1,-1000,1,1000]
ctr=[1,0]

def bfs(tar):
    cnt = 0
    q = deque()
    q.appendleft(1001)
    vi[1][1] = True
    while len(q)!=0:
        cur = q.pop()
        x = cur//1000
        y = cur%1000
        if cur==tar:
            print(cnt+1)
            return
        for i in range(4):
            if ch[x+dx[i]][y+dy[i]]=='1' and not vi[x+dx[i]][y+dy[i]]:
                vi[x+dx[i]][y+dy[i]] = True
                q.appendleft(cur+d[i])
                ctr[(cnt+1)%2]+=1
        ctr[cnt%2]-=1
        if(ctr[cnt%2]==0):
            cnt+=1

n,m=map(int, sys.stdin.readline().strip().split())
ch.append(" "*(m+2))
vi.append([False]*(m+2))
for _ in range(n):
    ch.append(" " + sys.stdin.readline().strip() + " ")
    vi.append([False]*(m+2))
ch.append(" "*(m+2))
vi.append([False]*(m+2))
bfs(n*1000+m)