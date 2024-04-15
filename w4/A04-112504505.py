'''
Assignment4
Name:梁耕嘉
Student Number: 112504505
Course 2023-CE1001-資電學士班
'''
from math import sqrt
def calculate_deviation(grades):
    #初始化總和
    sum = 0
    sum1 = 0
    #將在grades 裡的成績都加起來
    for score in grades:
        score = float(score)
        sum += score
    #除以數量得平均
    av = sum / len(grades)
    #算出離均差平方和
    for score in grades:
        score = float(score)
        sum1 += (score - av) ** 2
    #回傳標準差
    return round(sqrt(sum1 / len(grades)), 2)

def read_grades_from_file(input_file):
    #打開檔案
    f = open(input_file, "r")
    #初始化陣列
    grades = []
    #將每一行的成績加入陣列
    for row in f:
        #去掉換行符號
        if "\n" in row:
            grades.append(row[0:-1])
        else:
            grades.append(row)
    #關閉檔案
    f.close()
    return grades

def write_result_to_file(std_deviation):
    #打開結果檔案
    result = open("result.txt", "w")
    #寫入標準差
    result.write("Standard Deviation:"+ str(std_deviation))
    #關閉檔案
    result.close()

#將成績讀入陣列中
grades = read_grades_from_file("student_scores.txt")
#計算標準差
dev = calculate_deviation(grades)
#寫入結果
write_result_to_file(dev)

