def is_eleven(num):
    num = str(num)[::-1]
    odd_sum = 0
    even_sum = 0
    n = 0
    while n < len(num):
        odd_sum += int(num[n])
        if n + 1 >= len(num):
            break
        even_sum += int(num[n + 1])
        n += 2
    diff = odd_sum - even_sum
    if diff < 0:
        diff = -diff
    if diff % 11 == 0:
        return True
    else:
        return False
while True:
    num = int(input(""))
    if num == 0:
        break
    if is_eleven(num):
        print("{} is a multiple of 11.".format(num))
    else:
        print("{} is not a multiple of 11.".format(num))
