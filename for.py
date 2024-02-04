string='hello'
for i in range(len(string)):
    print(string[i])

for i in range(4):
    print('*'*5)

for i in range(5):
    print('*'*(i+1))

for i in range(1,8):
    for j in range(0,i):
        print(i,end='')
    print()

for i in range(6):
    print('/'*2*i,'!'*(22-4*i),'/'*2*i,sep='')

