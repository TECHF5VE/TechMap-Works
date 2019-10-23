def su(d=[]):
    n = len(d)
    z = 0
    for x in range(0, n):
        z = z+d[x]
    return z


print("输入几个数字")
m = input()
mm = m.split(",")
li = [int(mm[i]) for i in range(len(mm))]
print(su(li))