n, m = map(int, (input().split(" ")))
board = [""] * n
for i in range(0, n):
    board[i] = input()
check_0 = [[False for i in range(0,m)] for j in range(0,n)]
check_1 = [[False for i in range(0,m)] for j in range(0,n)]
for i in range(0, n):
    for j in range(0, m):
        if i%2==0:
            if j%2==0:
                if board[i][j]=="B":
                    check_0[i][j] = True
            else:
                if board[i][j]=="W":
                    check_0[i][j] = True
        else:
            if j%2==0:
                if board[i][j]=="W":
                    check_0[i][j] = True
            else:
                if board[i][j]=="B":
                    check_0[i][j] = True
for i in range(0, n):
    for j in range(0, m):
        if i%2==0:
            if j%2==0:
                if board[i][j]=="W":
                    check_1[i][j] = True
            else:
                if board[i][j]=="B":
                    check_1[i][j] = True
        else:
            if j%2==0:
                if board[i][j]=="B":
                    check_1[i][j] = True
            else:
                if board[i][j]=="W":
                    check_1[i][j] = True
minmum = 2500
for i in range(0, n-8+1):
    for j in range(0, m-8+1):
        cnt_0 = 0
        cnt_1 = 0
        for k in range(i, i+8):
            cnt_0 += check_0[k][j:j+8].count(True)
            cnt_1 += check_1[k][j:j+8].count(True)
        cnt = cnt_0 if cnt_0<cnt_1 else cnt_1
        minmum = cnt if cnt<minmum else minmum
print(minmum)