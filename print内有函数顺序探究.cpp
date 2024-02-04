#include<stdio.h>

int seq=0;
int id=0;

int change_id()
{
    id+=100;
    seq+=1000;
    return id; 
}

int change_seq()
{
    seq-=100;
    return seq; 
}
int main(){
    printf("seq=%d,id=%d,seq=%d\n",change_seq(),change_id(),change_seq());
return 0;
}
