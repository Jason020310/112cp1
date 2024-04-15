'''
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1001-資電學士班
'''

#使用者輸入範圍
lower = int(input().replace("\r",""))
upper = int(input().replace("\r",""))

#設定總和初始值
sum = 0

#質數判定函數
def is_prime(n):
    if n == 1:
        return False
    #一個一個除 如果整除即不是質數
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

#檢查有無錯誤輸入
if lower > upper:
    print("Error!")
else:
    #從下限到上限將所有質數加起來
    for i in range(lower , upper + 1):
        if is_prime(i):
            sum += i
    #印出結果
    print("The answer is", sum)


