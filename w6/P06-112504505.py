'''
Practice6
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1003-資電學士班
'''
#初始化列表 
works = []
def modify_job_data(index, factor, num):
    #如果index 超出資料範圍
    if index > len(works):
        print("No such job data")
    else:
        #更改資料
        if factor == "name":
            works[index - 1][factor] = num
        else:
            works[index - 1][factor] = int(num)

def create_job(workdata):
    #創建dictionary
    work = {}
    work["name"] = workdata[0]
    work["salary"] = int(workdata[1])
    work["work"] = int(workdata[2])
    #加入資料中
    works.append(work)
    return

def list_job(factor):
    #複製一份
    #不可用sorted_works = works ! 會改到原本資料
    sorted_works = works.copy()
    #按照輸入順序印出
    if factor == "name":  
        for com in works:
            print("{} {} {}".format(com["name"], com["salary"], com["work"]))
        return
    elif factor == "salary":
        #bubble sort
        for i in range(len(works)):
            for j in range(len(works) - 1):
                if sorted_works[j]["salary"] < sorted_works[j+1]["salary"]:
                    temp = sorted_works[j]
                    sorted_works[j] = sorted_works[j+1]
                    sorted_works[j+1] = temp
    elif factor == "work":
        #bubble sort
        for i in range(len(works)):
            for j in range(len(works) - 1):
                if sorted_works[j]["work"] > sorted_works[j+1]["work"]:
                    temp = sorted_works[j]
                    sorted_works[j] = sorted_works[j+1]
                    sorted_works[j+1] = temp
    #印出結果
    for com in sorted_works:
        print("{} {} {}".format(com["name"], com["salary"], com["work"]))
    return
        
while True:
    #接受指令
    print("Please enter command")
    i = input("").replace("\r","")
    if i == "1":
        print("Please enter job data")
        workdata = input("").replace("\r","").split()
        create_job(workdata)
        print("Adding job data")
    elif i == "2":
        print("Please enter factor")
        factor = input().replace("\r","")
        list_job(factor)
    elif i == "3":
        print("Please enter work number")
        index = int(input("").replace("\r",""))
        order = input("").replace("\r","").split()
        modify_job_data(index , order[0],order[1])
    #停止指令
    elif i == "4":
        print("Stopping program")
        break
    #錯誤指令
    else:
        print("No such command")
        continue


