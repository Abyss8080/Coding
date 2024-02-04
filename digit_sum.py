def digit_sum(n):
    if n < 0:
        n = -n
    count = 0
    while n != 0:
        count += n % 10
        n //= 10
    return count

print(digit_sum(17092))