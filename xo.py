def xo(s=3):
    for i in range(s):
        for j in range(s):
            if j==i or j==s-i-1:
                print('X',end='')
            else:
                print('O',end='')
        print()

def main():
    s=int(input("size=?"))
    xo(s)
    
main()