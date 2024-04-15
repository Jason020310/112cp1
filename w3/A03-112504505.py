#接受幾個輸入
time = int(input().replace("\r", ""))
#初始化總和
sum = 0
#中獎號碼(前兩個為大獎)
money_number = ["21981893", "39597522", "09505831","54219897", "17469638" ]
def check(input):
    #一個一個對普獎
    for i in range(2, 5):
        #從前面依序對子字串
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
#重複接受幾個輸入
for i in range(time):
    #接受輸入
    n = input().replace("\r", "")
    #如果開頭為小寫倒序並刪除字母
    if ord(n[0]) >= 97:
        n = n[1:][::-1]
    else:
    #大寫的話直接刪除字母
        n = n[1:9]
    #檢查有無中大獎
    if money_number[0] in n:
        sum += 10000000
    elif money_number[1] in n:
        sum += 2000000
    #檢查普獎
    sum += check(n)
print(sum)
