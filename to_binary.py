def to_binary(n):
    s = ""
    while n != 0:
        s = str(n % 2) + s
        n = n // 2
    print(s)

def main():
    n=int(input("Please input an integer:"))
    to_binary(n)

main()