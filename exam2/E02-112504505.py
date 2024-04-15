sum = 0
setence = input("").replace("\r","")
for character in setence:
    sum += (ord(character) + 3)
    print(chr(ord(character) + 3),end ="")
print("")
print(sum)