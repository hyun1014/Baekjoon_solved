from itertools import permutations
n = int(input())
num = list(map(int, input().split(" ")))
opr = list(map(int, input().split(" ")))
oprlist = set(permutations(list('+'*opr[0] + '-'*opr[1] + '*'*opr[2] + '/'*opr[3])))
mx = -1000000000
mn = 1000000000
for op in oprlist:
    result = num[0]
    for o in range(n-1):
        if op[o]=='+':
            result += num[o+1]
        elif op[o]=='-':
            result -= num[o+1]
        elif op[o]=='*':
            result *= num[o+1]
        else:
            if result<0:
                result *= -1
                result = result // num[o+1]
                result *= -1
            else:
                result = result // num[o+1]
    if result>mx:
        mx = result
    if result<mn:
        mn = result

print(mx)
print(mn)
    