# 只考虑正因数
def print_factors(n):
    if n < 0:
        n = -n
    for i in range(1, n // 2 + 1):
        if n % i == 0:
            print(i, "and", end=' ')
    print(n)


print_factors(26)
