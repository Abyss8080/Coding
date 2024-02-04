def repl(string, n):
    string1=""
    if n>0:
        for i in range(n):
           string1+=string
           #print(string)
    return string1
    
def main():
    string=input("new string is ?")
    n=int(input("repeat number is ?"))
    string=repl(string, n)
    print(string)
    
main()