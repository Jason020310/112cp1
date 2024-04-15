sum = 0
while True:
    num = int(input(""))
    if num % 2 == 0:
        print("Ending the game. The sum is {}.".format(sum))
        break
    elif num % 2 == 1 and num > 0:
        sum += num
    else:
        print("Error!")
        break