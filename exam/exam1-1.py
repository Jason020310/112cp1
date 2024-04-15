def check(words):
    for i in range(len(words) - 1):
        if words[i][-1] != words[i+1][0]:
            return False
    return True

times = int(input(""))
words = []
for i in range(times):
    word = input("")
    words.append(word[::-1])
if check(words):
    print("Success!")
else:
    print("Fail!")

