'''
Practice1
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1003B-資電學士班
'''
#奇數 or 偶數
odd_or_even = input().replace("\r","")

#使用者輸入範圍 
lower = int(input().replace("\r",""))
upper = int(input().replace("\r",""))

#設定總和初始值
sum = 0

#檢查有無錯誤輸入
if (lower >= upper) or (odd_or_even != "odd" and odd_or_even != "even") :
    print("Error!")

#將所球數字加起來
else:
    #從下限到上限將所求加起來
    for i in range(lower, upper + 1):
        if i % 2 == 0 and odd_or_even == "even":
            sum += i
        elif i % 2 == 1 and odd_or_even == "odd":
            sum += i
        #印出結果
    print("The answer is", sum)

