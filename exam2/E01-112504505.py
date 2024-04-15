def move(x , y, d):
    if d == 1:
        x = x + 1
    elif d == 2:
        y = y - 1
    elif d == 3:
        x = x - 1
    elif d == 4:
        y = y + 1
    return (x , y)
result = []
for j in range(2):
    x = 0
    y = 0
    d = 1
    t = int(input().replace("\r", ""))
    first = input().replace("\r","")
    for i in range(t):
        if first[i] == "S":
            (x , y ) = move(x , y, d)
        elif first[i] == "R":
            if d == 4:
                d = 1
            else:
                d = d + 1
    result.append(x)
    result.append(y)
print("Peter is at ({},{}).".format(result[0],result[1]))
print("Jason is at ({},{}).".format(result[2],result[3]))
print((result[0] - result[2]) ** 2 + (result[1] - result[3]) ** 2) 


