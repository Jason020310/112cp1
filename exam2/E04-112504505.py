""""input = input().replace("\r", "")
input = input.split()
56
s = input[0]
a = input[1]
#能活幾天
y = input[2]
m = input[3]
d = 1
every_gen = [s]
die_num = 0
while (s > 0 and m > 0):
    if d % a == 0:
        s += (s / 2)
        every_gen.append([s / 2])
    die_num = 

    

    
    d += 1
    m -= 1

"""