import sys
v=[]
vi=[]
q=[]
n=int(sys.stdin.readline().strip())
m=int(sys.stdin.readline().strip())
for _ in range(n+1):
    v.append([])
    vi.append(False)
for _ in range(m):
    a,b=map(int,sys.stdin.readline().strip().split())
    v[a].append(b)
    v[b].append(a)
q.append(1)
vi[1]=True
while q:
    t=q[0]
    le=len(v[t])
    for i in range(le):
        if not vi[v[t][i]]:
            vi[v[t][i]]=True
            q.append(v[t][i])
    del q[0]
print(vi.count(True)-1)