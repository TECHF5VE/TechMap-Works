def m(n):
    if n == 1:
        return 1
    if n == 2:
        return 1/2
    if n > 2:
        return 1/n+m(n-2)


print("请输入一个正整数：")
num = int(input())
print(m(num))









