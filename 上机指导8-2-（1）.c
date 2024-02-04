
#include <stdio.h>
#include <stdlib.h>


int main() {
	int ar[10] = {11, 13, 15, 17, 19, 21, 23, 25, 27, 29,};
	int *pt;
	pt = ar;
	printf("ar[0]=%p\n", &ar[0]);
	printf("pt   =%p\n", pt);
	printf("*pt  =%d\n", *pt);
	//*pt=pt¡¾0¡¿=ar¡¾0¡¿=11
	printf("*pt+3=%d\n", *pt + 3);
	//*pt+3=pt[0]+3=11+3=14
	printf("pt[3]=%d\n", pt[3]);
	//pt[3]=pt[0]+3=*(pt+3)=ar[3]=17
	printf("&*pt =%d\n", &*pt);
	//&*pt=pt
//	printf("*pt[3]=%d", *pt[3]);
//	//pt[3]=*£¨pt+3£©
	printf("*(pt+3)=%d\n", *(pt + 3));

	printf("*pt++  =%d\n", *pt++);
	printf("*pt=%d\n", *pt);
	//*pt++=*(pt++)=*pt=11
	//*pt=pt[1]=13
	printf("*(pt++)=%d\n", *(pt++));
	printf("*pt=%d\n", *pt);
	//*(pt++)=pt[1]=13
	//*pt=pt[2]=15
	printf("(*pt)++=%d\n", (*pt)++);
	printf("*pt=%d\n", *pt);
	//(*pt)++=*pt=15
	//*pt=*pt+1=16



	system("PAUSE");
	return 0;
}