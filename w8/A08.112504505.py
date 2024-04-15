'''
Assignment8
Name:梁耕嘉
Student Number: 112504505
Course 2023-CE1001-資電學士班
'''
def first():
    print("Burger:")
    hams = []
    #將所有的漢堡(key)存入hams
    for key in datas:
        hams.append(key)
    #排序
    hams.sort()
    print(hams)
def second():
    pop = []
    print("Popular:")
    max = 0
    #如果有漢堡的投票人數比max大 max 改成它
    for ham in datas:
        num = len(datas[ham])
        if num > max:
            max = num
    #找到那個最受歡迎的漢堡存入pop
    for ham in datas:
        if len(datas[ham]) == max:
            pop.append(ham)
    #排序
    pop.sort()
    #印出最受歡迎的漢堡與投給他的人
    for ham in pop:
        print(ham, max)
        datas[ham].sort()
        print(datas[ham])
    #回傳最受歡迎名單
    return pop
def third(pop):
    print("Recommend:")
    hams = []
    rec = set()
    names = set()
    #找出所有投給最受歡迎漢堡的人存入names
    for ham in pop:
        for name in datas[ham]:
            names.add(name)
    #找到他們除了最受歡迎漢堡外還投給那些漢堡存入hams
    for name in names:
        for ham in datas:
            if name in datas[ham] and ham not in pop:
                hams.append(ham)
    max = 0
    #找到hams裡出現最多次的漢堡
    for ham in hams:
        num = hams.count(ham)
        if num > max :
            max = num
    for ham in hams:
        if hams.count(ham) == max:
            rec.add(ham)
    #排序
    rec = list(rec)
    rec.sort()
    #印出結果
    if len(rec) == 0:
        print("None")
    else:
        print(rec)
def fourth():
    unpop = []
    print("Unpopular:")
    min = 10
    #如果有漢堡投票人數比min少 將min 改成它
    for ham in datas:
        num = len(datas[ham])
        if num < min:
            min = num
    #找到最不受歡迎漢堡存入unpop
    for ham in datas:
        if len(datas[ham]) == min:
            unpop.append(ham)
    #排序
    unpop.sort()
    #以防有所有人都投同一個漢堡
    unpop = list(set(unpop) - set(pop))
    if len(unpop) == 0:
        print("None")
    else:
        #印出最不受歡迎漢堡與投給他的人
        for ham in unpop:
            print(ham, min)
            datas[ham].sort()
            print(datas[ham])
    #回傳最不受歡迎名單
    return(unpop)
def fifth(pop,unpop):
    print("Difference: ")
    p = set()
    u = set()
    #將所有投給最受歡迎漢堡的人存入p
    for ham in pop:
        for i in datas[ham]:
            p.add(i)
    #將所有投給最不受歡迎漢堡的人存入u
    for ham in unpop:
        for i in datas[ham]:
            u.add(i)
    #diff 為投票給最受歡迎漢堡的人與投給最少人喜愛的漢堡的人的差集
    diff = list(p - u)
    #排序
    diff.sort()
    #印出結果
    if len(diff)==0:
        print("None")
    else:
        print(diff)
datas = {}
while True:
    #接受輸入
    vote = input("")
    #輸入終止條件
    if vote == "end":
        break
    else:
        #資料處理
        vote = vote.split()
        name = vote[0]
        ham = vote[1]
        #字典裡把漢堡當key 投票人組成的list 當value
        if ham not in datas:
            data = []
            data.append(name)
            datas[ham] = data
        else:
            datas[ham].append(name)
#呼叫函式
first()
pop = second()
third(pop)
unpop = fourth()
fifth(pop,unpop)