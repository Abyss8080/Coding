def print_square(min, max):
    for i in range(max-min+1):
        for j in range(min+i, max+1):
            print(j, sep='', end='')
        for k in range(min, min+i):
            print(k, sep='', end='')
        print()

        
def main():
    print_square(3, 7)

    
main()
