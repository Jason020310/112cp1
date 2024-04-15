def is_jolly(gap):
    print(gap)
    nums = []
    for i in range(len(gap)):
        nums.append(i + 1)
    print(nums)
    for diff in gap:
        if diff in nums:
            nums.remove(diff)
        else:
            return False
    return True

try:
    while True:
        gap = []
        sequence = input()
        sequence = sequence.split()
        sequence = [int(x) for x in sequence] 
        for i in range(len(sequence) - 1):
            if sequence[i] > sequence[i + 1]:
                diff = sequence[i] - sequence[i + 1]
            else:
                diff = sequence[i + 1] - sequence[i]
            gap.append(diff)
        if is_jolly(gap):
            print("Jolly")
        else:
            print("Not jolly")
except EOFError:
    pass
