times = int(input(""))
for i in range(times):
    s = 0
    length = int(input(""))
    sequence =  input("")
    sequence = sequence.split()
    for i in range(length):
        for j in range(length - 1):
            if int(sequence[j]) > int(sequence[j + 1]):
                tmp = int(sequence[j]) 
                sequence[j] = int(sequence[j + 1])
                sequence[j + 1] = tmp
                s += 1
    print("Optimal train swapping takes {} swaps.".format(s))
