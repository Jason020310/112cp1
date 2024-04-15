'''
Assignment6
Name:梁耕嘉
Student Number: 112504505
Course 2023-CE1001-資電學士班
'''
#初始化資料庫
menus = {1: [], 2:[] ,3:[] ,4:[] , 5:[] , 6:[] , 7:[] }
orders = {1: {}, 2:{} ,3:{} ,4:{} , 5:{} , 6:{} , 7:{} }
price = {}
def is_in_menu(date, dish):
    #檢查有無在菜單裡
    if dish in menus[date]:
        return True
    else:
        return False

def calculation(date):
    income = 0
    cost = 0
    for i in orders[date]:
        #得到數量
        p = int(price[i][0])
        c = int(price[i][1])
        #算出收入跟成本
        income += p * orders[date][i]
        cost += c * orders[date][i]
    return income , cost

def create_menu(dish):
    #做資料處理
    price[dish[1]] = [dish[2],dish[3]]
    dates = dish[0].split(",")
    #加進資料
    for i in dates:
        menus[int(i)].append(dish[1])
    return

def make_order(order):
    #如果已在菜單裡加上去
    if order[1] in orders[int(order[0])]:
        orders[int(order[0])][order[1]] += int(order[2])
    #不在的話就創建
    else:
        orders[int(order[0])][order[1]] = int(order[2])
    return

def list_menu(date):
    #如果無此資料
    if len(menus[date]) == 0:
        print("No such menu data")
    else:
        #印出資料
        for dish in menus[date]:
            print(dish, price[dish][0], price[dish][1])

while True:
    #接受指令
    print("Please enter command")
    i = int(input("").replace("\r",""))
    if i == 1:
        print("Please enter dish data")
        #將資料分開
        dish = input("").split()
        create_menu(dish)
        print("Adding " + dish[1])
    elif i == 2:
        print("Please enter date")
        date = int(input("").replace("\r",""))
        list_menu(date)
    elif i == 3:
        print("Please enter order")
        #做資料處理
        order = input("").replace("\r","").split()
        #檢查有無在菜單裡
        if is_in_menu(int(order[0]), order[1]):
            #點餐
            make_order(order)
            #印出訂單
            print("Order {} {} on date {}".format(int(order[2]), order[1], order[0]))
        else:
            print("No such dish data")
    elif i == 4:
        print("Please enter date")
        #做資料處理
        date = int(input("").replace("\r",""))
        #做收入成本計算
        income, cost = calculation(date)
        #印出
        print("Income: {} Cost: {}".format(income,cost))
    #停止指令
    elif i == 5:
        print("Stopping program")
        break
    #錯誤訊息
    else:
        print("No such command")
        continue

