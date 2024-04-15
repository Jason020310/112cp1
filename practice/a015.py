try:
    while True:
        matrix = []
        size = input("")
        size = size.split()
        row = int(size[0])
        col = int(size[1])
        for i in range(row):
            num = input("")
            num = num.split()
            nums = []
            for j in range(col):
                nums.append(num[j])
            matrix.append(nums)
        for i in range(col):
            for j in range(row):
                print(matrix[j][i],end=" ")
            print()
except EOFError:
    pass