def connect(all, n):
    if n == len(all):
        return ""
    else:
        for i in range(len(all)):
            return result.append(all[i][n] + connect(all,n + 1))

rome_number = input("").replace("\r","").split(",")
all = []
result = []
correspond = {"II": "abc", "III": "def", "IV": "ghi","V": "jkl","VI": "mno","VII": "pqrs", "VIII":"tuv", "IX": "wxyz" }
for rome in rome_number:
    all.append(correspond[rome])

connect(all, 0)
print(result)


    



