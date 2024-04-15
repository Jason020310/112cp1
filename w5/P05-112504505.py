'''
Practice5
Name: 梁耕嘉
Student Number: 112504505
Course 2023-CE1003-資電學士班
'''
def readfile():
    #初始化二進位與十進位陣列
    decs = []
    bins = []
    #開啟並讀取第一行
    f = open("input.txt", "r")
    times = int(f.readline()[0:-1])
    #將每行數字讀進decs
    for i in range(times):
        dec = f.readline().replace("\n", "")
        decs.append(int(dec))
    #由小到大排序
    decs.sort()
    #換成二進位存進bins
    for  dec in decs:
        bin = decimal_to_binary(dec)
        bins.append(bin)
    return decs, bins

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
            
def find_value(bins):
    max = 0
    #找尋最大值
    for bin in bins:
        #如果有一數比max 大 將max 換掉
        if len(bin) > max:
            max = len(bin)
    #回傳該位數可以存的最大值
    return 2 ** max - 1

def find_ones(bins):
    max_index = []
    maxs = []
    counts = []
    #算出每個數的1的個數存入counts
    for bin in bins:
        count = 0
        for c in bin:
            #只有1 & 1 才會是1
            count += int(c) & 1
        counts.append(count)
    #將有最多1 的數的index存在 max_index
    for i in range(len(counts)):
        if counts[i] == max(counts):
            max_index.append(i)
    #將有最多1的數換成十進位存入maxs
    for index in max_index:
        maxs.append(binary_to_decimal(bins[index]))
    return maxs

    
def find_zeros(number):
    max_index = []
    maxs = []
    counts = []
    #算出每個數的1的個數存入counts
    for bin in bins:
        count = 0
        for c in bin:
            #只有1 XOR 1 才會是1
            count += int(c) ^ 1
        counts.append(count)
    #將有最多1 的數的index存在 max_index
    for i in range(len(counts)):
        if counts[i] == max(counts):
            max_index.append(i)
    #將有最多1的數換成十進位存入maxs
    for index in max_index:
        maxs.append(binary_to_decimal(bins[index]))
    return maxs

def write_file(decs, bins):
    #打開檔案
    f = open("output.txt", "w")
    #寫入十進位二進位陣列
    print(decs, file = f)
    print(bins, file = f)
    #找到最大值
    big = find_value(bins)
    print(big, file = f)
    #找到最多1 跟最多0 的數字
    ones = find_ones(bins)
    zeros = find_zeros(bins)
    #印出答案
    print(ones,file = f)
    print(zeros, file = f)

#讀檔案
decs, bins = readfile()
#印檔案
write_file(decs, bins)
