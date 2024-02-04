def print_palindrome():
    string=input("please input a string:")
    string=string.upper()
    flag=True
    for i in range(len(string)):
        j=len(string)-i-1
        if i>=j:
            if string[i]!=string[j]:
                flag=False
    if flag:
        print("YES")
    else:
        print("NO")

def main():
    print_palindrome()
    
main()