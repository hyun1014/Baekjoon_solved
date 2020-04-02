n = int(input())
cnt = 0
for i in range(0,n):
    check = [False]*26
    flag = True
    s = input()
    lng = len(s)
    if lng==0:
        continue
    prev = s[0]
    check[ord(prev)-97] = True
    for j in range(1, lng):
        if s[j]==prev:
            continue
        else:
            if check[ord(s[j])-97]:
                flag = False
                break
            else:
                check[ord(s[j])-97] = True
                prev = s[j]
    if flag:
        cnt+=1
print(cnt)