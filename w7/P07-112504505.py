'''
Practice7
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1003-資電學士班
'''
def GCD_LCM(a = 0, b = 0):
    #確保a > b
    if a > b:
        tmp = a
        a = b
        b = tmp
    factors = []
    #尋找所有公因數
    for i in range(1, a + 1):
        if a % i == 0 and b % i == 0:
            factors.append(i)
    #最大公因數
    max = factors[-1]
    a = a // max
    b = b // max
    #最小公倍數
    min = max * a * b
    return max , min
        
def is_prime(c = 0):
    #如果等於2
    if c == 2:
        return "yes"
    else:
        #如果有數能整除 表示他不是質數
        for i in range(2, c):
            if c % i  == 0:
                return "no"
        #沒有即是質數
        return "yes"
def fibonacci(d = 0):
    #base condition
    if d == 0:
        return 0
    elif d == 1:
        return 1
    #遞迴關係式
    else:
        return fibonacci(d - 1) + fibonacci(d - 2)
def three_multiple_n_and_add_one(e = 0, f = 0):
    #確保 e > f
    if e > f:
        tmp = e
        e = f
        f = tmp
    length = []
    #算出所有len cycle 值
    for i in range(e, f + 1):
        length.append(calculate(i))
    return max(length)
def calculate(n = 0):
    x = 0
    #直到1 終止
    while n != 1:
        #關係式
        x += 1
        if n % 2 == 0:
            n = n // 2
        else:
            n = 3 * n + 1
    #輸出長度
    return x + 1

def main():
    games = []
    #輸入要玩的遊戲
    while True:
        game = int(input().replace("\r",""))
        #直到-1 為止
        if game == -1:
            break
        games.append(game)
    #輸入參數
    para = input().replace("\r","")
    para = para.split()
    #將參數都改成整數
    para = [int(i) for i in para]
    #沒有玩的訊息
    no = "you do not play the game!"
    #印出結果
    if 1 in games:
        max , min = GCD_LCM(para[0], para[1])
        print("Game 1 : {}, {}".format(max, min))
    else:
        print("Game 1 : {}".format(no))
    if 2 in games:
        print("Game 2 : {}".format(is_prime(para[2])))
    else:
        print("Game 2 : {}".format(no))
    if 3 in games:
        print("Game 3 : {}".format(fibonacci(para[3])))
    else:
        print("Game 3 : {}".format(no))
    if 4 in games:
        print("Game 4 : {} ".format(three_multiple_n_and_add_one(para[4], para[5])))
    else:
        print("Game 4 : {}".format(no))
#呼叫主函式
if __name__== "__main__":
    main()

