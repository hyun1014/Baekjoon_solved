n = int(input())
if n<100:
    print(n)
    exit()
else:
    cnt = 0
    for i in range(100, n+1):
        if i//100 - (i//10)%10 == (i//10)%10 - i%10:
            cnt += 1
    print(99+cnt)
    exit()