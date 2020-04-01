n=int(input())
if n==1:
    print("*")
else:
    for _ in range(0,n):
        for i in range(0,n):
            if i%2:
                print(" ",end="")
            else:
                print("*",end="")
        print()
        for i in range(0,n):
            if i%2:
                print("*",end="")
            else:
                print(" ",end="")
        print()