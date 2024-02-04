import random


def three_heads():
    count = 0
    while count != 3:
        i = random.randint(0, 1)
        if i == 1:
            print("H", end=' ')
            count += 1
        else:
            print("T", end=' ')
            count = 0
    print('\n',"Three heads in a row!",sep='')


three_heads()
