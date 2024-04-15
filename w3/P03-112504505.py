#要幾個輸入
time = int(input().replace("\r",""))
#初始化總和
sum = 0
#中獎號碼 (前兩個為大獎)
money_number = ["21981893", "39597522", "09505831","54219897", "17469638" ]

def check(input):
    #一個一個對普獎號碼
    for i in range(2, 5):
        #從前面開始切割一個一個比對
        for j in range(6):
            #如果後幾個數字跟普獎號碼一樣
            if (money_number[i][j:] == input[j:]):
                if j == 0:
                    return 200000
                elif j == 1:
                    return 40000
                elif j == 2:
                    return 10000
                elif j == 3:
                    return 4000
                elif j == 4:
                    return 1000
                elif j == 5:
                    return 200
    return 0
#接受幾個輸入
for i in range(time):
    n = input().replace("\r","")
    #如果中大獎
    if n == money_number[0]:
        sum += 10000000
    elif n == money_number[1]:
        sum += 2000000
    #看有無普獎
    sum += check(n)
print(sum)




