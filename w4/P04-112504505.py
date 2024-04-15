'''
Practice4
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1003-資電學士班
'''
def classify_grades(grades):
    #將成績做分類(統計)
    for score in grades:
        #將string 換成float
        score = float(score)
        if score >= 90:
            s["A"] += 1
        elif 80 <= score < 90:
            s["B"] += 1
        elif 70 <= score < 80:
            s["C"] += 1
        elif 60 <= score < 70:
            s["D"] += 1
        else:
            s["F"] += 1
            
def write_result_to_file(output_file):
    #打開(建立)result.txt
    result = open(output_file, "w")
    #寫入統計結果
    for num in s:
        c = num + ":" + str(s[num]) + "\n"
        result.write(c)
    #關閉檔案
    result.close()

def read_grades_from_file(file_path):
    #打開檔案
    f = open(file_path,"r")
    #初始化陣列
    grades = []
    #將成績讀入陣列
    for row in f:
        #去掉換行符號
        if "\n" in row:
            grades.append(row[0:-1])
        else:
            grades.append(row)
    f.close()
    return grades
#初始化字典
s = {"A" : 0, "B" : 0, "C": 0, "D":0, "F":0}

#將成績讀取到陣列中
grades = read_grades_from_file("student_scores.txt")

#將陣列裡的成績做統計
classify_grades(grades)

#將結果寫入檔案
write_result_to_file("result.txt")





