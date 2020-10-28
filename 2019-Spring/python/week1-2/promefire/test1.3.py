f = open(r"f:\file.txt")
for line in f:
    m = list(line)
    for num in range(len(m)):
        print(m[num])
f.close()


print("-------------------")
n = open(r"f:\file.txt")
print(n.readline())
n.close()

print("-------------------")
with open('f:/file.txt', 'r') as m:
    for line in m:
        print(line.split())
