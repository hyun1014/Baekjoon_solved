n=int(input())
if n==1:
    print(1)
elif n==2:
    print(2)
else:
    a=1
    b=2
    tmp=0
    while n>2:
        tmp=(a+b)%15746
        a=b
        b=tmp
        n-=1
    print(tmp)