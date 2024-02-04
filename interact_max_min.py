n = input("input a integer,or -1 to stop:")
n = int(n)
max = min = n
while n != -1:
    if n > max:
        max = n
    if n < min:
        min = n
    n = input("input a integer,or -1 to stop:")
    n = int(n)
if max == min == -1:
    print("No effective integer has been input!")
else:
    print("max=", max, end='\n')
    print("min=", min, end='\n')
