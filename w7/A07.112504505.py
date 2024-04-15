'''
Assignment7
Name:梁耕嘉
Student Number: 112504505
Course 2023-CE1001-資電學士班
'''
def maze(mazes = []):
    #從起點開始
    position = [1, 1]
    #直到還沒達到終點
    while position[0] != 7 or position[1] != 7:
        #如果連起點都不能走
        if mazes[position[0]][position[1]] == 0:
            return "no"
        #如果右邊可走就往右
        elif mazes[position[0]][position[1] + 1]  == 1:
            position = [position[0], position[1] + 1]
        #如果向下可走就往下
        elif mazes[position[0] + 1][position[1]]  == 1:
            position = [position[0] + 1, position[1]]
        #走到死路 就把路堵住
        else:
            mazes[position[0]][position[1]] = 0
            position = [1, 1]
    return "yes"
def perfect_numbers(b = 0):
    total = 0
    #將所有因數加起來
    for i in range(1,b):
        if b % i == 0:
            total += i
    #輸出結果
    if total == b:
        return "Perfect"
    elif total < b:
        return "Deficient"
    else:
        return "Abundant"
    
def is_prime(x=0):
    #如果是2變是質數
    if x == 2:
        return True
    else:
        #有數可整除x 即代表x 非質數
        for i in range(2, x):
            if x % i  == 0:
                return False
        #無其他因數即為質數
        return True       
def prime_factorization(b = 0):
    facs = []
    while is_prime(b) == False:
        for i in range(2, b):
            if b % i == 0:
                facs.append(i)
                b = b // i
                break
    facs.append(b)
    return facs
def carry_in_addition(a = 0, b = 0):
    #反轉a , b
    a = list(a[::-1])
    b = list(b[::-1])
    #初始化變數
    carry = 0
    i = 0
    while True:
        #如果不能加了就跳出迴圈
        if i > len(a) - 1 or i > len(b) - 1:
            break
        add = int(a[i]) + int(b[i])
        #進位就加一
        if add >= 10:
            carry += 1
        #計數
        i = i + 1
    #印出結果
    if carry == 0:
        return "No carry operation"
    elif carry == 1:
        return "1 carry operation"
    else:
        return str(carry) + " carry operations"
     
def factorial(e = 0):
    #base condition
    if e <= 0:
        return 1
    else:
        #遞迴關係式
        return e * factorial(e - 1)
    
def main():
    #輸入要玩的遊戲
    games = []
    while True:
        game = int(input().replace("\r",""))
        if game == -1:
            break
        games.append(game)
    #輸入遊戲參數
    para = input().replace("\r","")
    para = para.split()
    no = "you do not play the game!"
    #開始玩遊戲並印出結果
    if 1 in games:
        #初始化陣列
        mazes =[[0]*9 for i in range(9)]
        for i in range(9):
            row = input().replace("\r","")
            for j in range(9):
                mazes[i][j] = int(row[j])
        print("Game 1 : {}".format(maze(mazes)))
    else:
        print("Game 1 : {}".format(no))
    if 2 in games:
        print("Game 2 : {}".format(perfect_numbers(int(para[0]))))
    else:
        print("Game 2 : {}".format(no))
    if 3 in games:
        print("Game 3 : {}".format(prime_factorization(int(para[1]))))
    else:
        print("Game 3 : {}".format(no))
    if 4 in games:
        print("Game 4 : {} ".format(carry_in_addition(para[2],para[3])))
    else:
        print("Game 4 : {}".format(no))
    if 5 in games:
        print("Game 5 : {}".format(factorial(int(para[4]))))
    else:
        print("Game 5 : {}".format(no))
#呼叫主程式
if __name__== "__main__":
    main()