for i in range(1,11):
    print(i*i,end=" ")


m=0
for i in range(1,11):
    m=i
    for j in range(1,i):
        m+=i
    print(m,end=' ')

