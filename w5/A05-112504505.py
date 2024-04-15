'''
Assignment5
Name:梁耕嘉
Student Number: 112504505
Course 2023-CE1001-資電學士班
'''
def readfile():
    #開啟檔案
    f = open("input.txt", "r")
    #獲得要得行動
    action = f.readline()
    action = action[0:-1]
    if action == "convert":
        #看是二進位還是十進位
        b_or_d = f.readline()[0:-1]
        if b_or_d == "binary":
            binary_number = f.readline()
            #檢查是否為binary
            if binary_checker(binary_number) == False:
                result = "Error!"
            #換算成十進位
            else:
                result = binary_to_decimal(binary_number)
        elif b_or_d == "decimal":
            #讀取數字
            decimal_number = int(f.readline())
            #換成二進位
            result = decimal_to_binary(decimal_number)
    elif action == "calculate":
        r = f.readline()
        #檢查是否符合要求
        if operation_checker(r) == False:
            result = "Error!"
        else:
            #計算結果
            result = calculation(r)
    else:
        #錯誤輸出
        result = "Error!"
    #寫入結果並關閉檔案
    write_file(str(result))
    f.close()

def decimal_to_binary(dec):
    q = dec
    bin = []
    #不斷做短除法
    while q > 1:
        #存入餘數
        r = q % 2
        bin.append(str(r))
        q  = q // 2
    bin.append(str(q))
    #倒序
    bin.reverse()
    #合併成一個string
    bin_str = "".join(bin)
    return bin_str

def binary_to_decimal(bin):
    dec = 0
    i = 0
    #按照每一位數的權重加起來
    for c in bin[::-1]:
        dec +=  int(c) * (2 ** i)
        i += 1
    return dec

def binary_checker(x):
    #檢查是否每一位數都是1 or 0
    for c in x:
        if c not in ["1", "0"]:
            return False
    return True

def operation_checker(r):
    operation = r.split()[1]
    #檢查是否為加減乘除
    if operation not in ["+", "-", "*", "/"]:
        return False
    else:
        return True

def calculation(r):
    #獲取要做運算的兩個數
    slice = r.split()
    first = binary_to_decimal(slice[0])
    second = binary_to_decimal(slice[2])
    #做對應的運算輸出
    if "+" in slice:
        return first + second
    elif "-" in slice:
        return first - second
    elif "*" in slice:
        return first * second
    elif "/" in slice:
        return first / second
    
def write_file(result):
    #開啟檔案
    result_file = open("output.txt", "w")
    #寫入檔案
    result_file.write(result)
    #關閉檔案
    result_file.close()
#讀檔
readfile()










