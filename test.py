mylist=[]

def test():
    global mylist
    mylist.append(90)

def main():
    test()
    print(mylist)
    
main()