n=int(input())
w=[0 for i in range(n+1)]
dp0=[0]
dp1=[0]
for i in range(1,n+1):
    w[i]=int(input())
if n==1:
    print(w[1])
    exit()
if n==2:
    print(w[1]+w[2])
    exit()
dp0.extend([w[1],w[1]+w[2]])
dp1.extend([0, w[1]])
for i in range(3,n+1):
    a=dp0[i-2]+w[i]
    b=dp1[i-2]+w[i-1]+w[i]
    dp0.append(a if a>b else b)
    dp1.append(dp0[i-1] if dp0[i-1]>dp1[i-1] else dp1[i-1])
print(dp0[n] if dp0[n]>dp1[n] else dp1[n])