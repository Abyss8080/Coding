def smallest_largest():
    n=int(input("how many numbers do you want to enter?"))
    if n<=0:
        raise Exception("repeat number should be positive.")
    for i in range(1,n+1):
        print("number",i,':',end='')
        x=int(input())
        if i==1:
            smallest = x
            largest = x
        else:
            if smallest>x:
                smallest=x
            if largest<x:
                largest=x
    print("smallest=",smallest)
    print("largest=",largest)
    
def main():
    smallest_largest()

main()


