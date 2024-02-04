#这里标点不算字母/单词
def word_count(string):
    string=string.upper()
    count=0
    start=False
    end=False
    for i in string:
        if 'A'<=i<='Z':
            start=True
        elif i==' ':
            if start:
                end=True
                count+=1
                start=end=False
    if 'A'<=string[len(string)-1]<='Z':
        count+=1
    return count

def main():
    string= input("the string you want to count is:")
    print(word_count(string))
    
main()

