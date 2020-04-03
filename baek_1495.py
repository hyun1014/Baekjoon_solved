n,s,m=map(int,(input().split(" ")))
v=[0]
v.extend(list(map(int,(input().split(" ")))))
dp=[0]*(m+1)
dp[s]=1
print(dp)
for i in v[1:]:
    for j in range(0,m+1):
        if dp[j]%2:
            if j+i<=m:
                dp[j+i]+=2
            if j-i>=0:
                dp[j-i]+=2
    for j in range(m+1):
        dp[j]=(1 if dp[j]>=2 else 0)
for i in range(m,-1,-1):
    if dp[i]:
        print(i)
        break
else:
    print(-1)