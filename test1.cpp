#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char user[100]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	char buf[400]={0};
	strncpy(buf,"USER:",100);
	printf("%s\n",buf);
	strncpy(user,buf,100);
	snprintf(buf,400,"HELLO %s \n PASS:",user); 
	printf("%s\n",buf);
	printf("%s\n",user);
	
	return 0;
}
