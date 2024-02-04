import random


def coin_flip(filename):
    counth = 0
    count = 0
    with open(filename, "r") as f:
        strre = f.read().split()
        for c in strre:
            if c == "H":
                counth += 1
            print(c, sep="", end="")
            count += 1
            if count % 10 == 0:
                print()
    print()
    print("H's number is", counth, ",total number is", count, ",H'percent is",
        round(float(counth) / float(count), 4) * 100, "%")


def main():
    filename = "three_results.txt"
    count = 0
    allcount = 0
    with open(filename, "w") as f:
        while count != 3 or allcount <= 10:
            i = random.randint(0, 1)
            allcount += 1
            if i == 1:
                print("H", file=f)
                count += 1
                if count == 3 and allcount <= 10:
                    count = 0
            else:
                print("T", file=f)
                count = 0
    
    coin_flip(filename)


main()
