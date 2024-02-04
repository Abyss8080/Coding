import random
#或者采用循环return搭配
def Guess():
    global is_done, count
    count += 1
    print('请输入一个[1, 100]的整数：',end='')
    guess = int(input())
    if guess == num:
        is_done = True
        print('赢了，答案是:', num, '!',"猜测",count,"次",end='!')
    elif guess > num:
        print('高了')
    elif guess < num:
        print('低了')
    if count<10 and is_done==False:
        Guess()
        
def main():
    global num,is_done,count
    num = random.randint(1, 100)  # 获得一个随机数
    is_done = False  # 是否猜中的标记
    count = 0  # 玩家猜了几次
    Guess()
    if count==10 and is_done==False:
        print("很遗憾未能在10次内猜中数字",num)
    
main()



