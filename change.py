de = (6, 5, 4, 2, 1)
dedp = (0, 1, 2, 4, 5, 6)
col = 6


def print_changes(money):
    count = [0, 0, 0, 0, 0]
    for i in range(5):
        count[i] = money//de[i]
        money -= de[i]*count[i]
    return count

   
def greedy(money):
    count = print_changes(money)
    allcount = 0
    print("Greedy:")
    print(money, "元将兑换:", sep='', end='')
    for i in range(5):
        allcount += count[i]
        print(count[i], "张", de[i], "元纸币", sep='', end='')
        print(end=',')
    print()
    print("共计", allcount, "张.")


def find_road(data, money, table):
    count = [0 for i in range(col)]
    print("   ", dedp, "min")
    for i in range(money + 1):
        print(i, ":", table[i], "", data[i])
    while money != 0:
        index = table[money].index(data[money])
        count[index] += 1
        money -= dedp[index]
    return count


def dynamics(money):
    data = [0 for i in range(money + 1)]
    table = [[0 for i in range(col)] for j in range(money + 1)]
    for i in range(1, money + 1):
        min = 100
        for j in range(1, col):
            index = i - dedp[j]
            if index >= 0:
                table[i][j] = data[index] + 1
                if table[i][j] > 0 and table[i][j] < min:
                    min = table[i][j]
        data[i] = min
    count = find_road(data, money, table)
    return data, count
    
    
def DP(money):
    allcount, count = dynamics(money)
    print("DP:")
    print(money, "元将兑换:", sep='', end='')
    for i in range(col-1):
        print(count[col - 1 - i], "张", dedp[col - 1 - i], "元纸币", sep='', end='')
        print(end=',')
    print()
    print("共计", allcount[money], "张.")


def main():
    money = 19
    greedy(money)
    print()
    DP(money)
   
    
main()
 