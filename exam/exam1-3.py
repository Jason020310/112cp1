def pos(x):
    if x > 0:
        return x
    else:
        return -x
def move(x , y, d):
    if d == 1:
        x = x - 1
    elif d == 2:
        y = y + 1
    elif d == 3:
        x = x + 1
    elif d == 4:
        y = y - 1
    return (x , y)
result = []
for j in range(2):
    x = 0
    y = 0
    d = 4
    t = int(input().replace("\r", ""))
    first = input().replace("\r","")
    for i in range(t):
        if first[i] == "B":
            (x , y ) = move(x , y, d)
        elif first[i] == "R":
            if d == 1:
                d = 4
            else:
                d = d - 1
    result.append(x)
    result.append(y)
print("Will is at ({},{}).".format(result[0],result[1]))
print("Peter is at ({},{}).".format(result[2],result[3]))
print(pos(result[0]) + pos(result[1]))
print(pos(result[2]) + pos(result[3]))

