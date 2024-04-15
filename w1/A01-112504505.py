'''
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1001-資電學士班
'''
x = int(input("請輸入第一根木棍長度:"))
y = int(input("請輸入第二根木棍長度:"))
z = int(input("請輸入第三根木棍長度:"))

if x ** 2 + y ** 2 == z ** 2:
    print("可以成功組成直角三角形")
elif y ** 2 + z ** 2 == x ** 2:
    print("可以成功組成直角三角形")
elif x ** 2 + z ** 2 == y ** 2:
    print("可以成功組成直角三角形")
else:
    print("不可以組成直角三角形")


 
