'''
Practice8
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1003-資電學士班
'''
def first(a, b ,c):
    #差集
    only_a = list(a - b - c)
    only_b = list(b - a - c)
    only_c = list(c - a - b)
    #排序
    only_a.sort()
    only_b.sort()
    only_c.sort()
    print(only_a, only_b, only_c)
def second(a , b, c):
    #計算個別聯集長度
    ab = len(a | b)
    bc = len(b | c)
    ac = len(a | c)
    print(ab, bc, ac)
def third(a, b, c):
    #兩個兩個交集
    ab = list(a & b)
    bc = list(b & c)
    ac = list(a & c)
    #排序
    ab.sort()
    bc.sort()
    ac.sort()
    print(ab, bc , ac)
def fourth(a, b, c):
    #三個交集
    abc = list(a & b & c)
    abc.sort()
    print(abc)
def fifth(a, b, c):
    #所有聯集
    all = len(a | b | c)
    print(all)
datas = {}
a = set()
b = set()
c = set()
while True:
    #直到接收到end
    data = input("")
    if data == "end":
        break
    else:
        name = data.split()[0]
        #如果還未有這個名字出現，則添加
        if name not in datas:
            com = []
            com.append(data.split()[1])
            datas[name] = com
        #有的話增加新資訊
        else:
            datas[name].append(data.split()[1])
#做分類 
for name,coms in datas.items():
    for com in coms:
        if com == "A":
            a.add(name)
        elif com == "B":
            b.add(name)
        else:
            c.add(name)
first(a, b ,c)
second(a, b, c)
third(a, b, c)
fourth(a, b, c)
fifth(a, b, c)