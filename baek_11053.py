n=int(input())
a=[0]
dp=[0]*(n+1)
a.extend(map(int,input().split(" ")))
for i in range(1,n+1):
    for j in range(0,i):
        if a[j]<a[i] and dp[j]+1>dp[i]:
            dp[i]=dp[j]+1
print(sorted(dp)[len(dp)-1])
print(sorted(dp))