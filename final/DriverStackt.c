#include "stackt.h"
#include "dataresep.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	Stack S;
	int i;
	printf("Masukkan bilangan = 0 jika ingin berhenti\n");
	do{
		printf("masukkan kode bahan yg ingin dimasukkan dalam tumpukkan : ");
		scanf("%d",&i);
		if(i!=0){
			Push(&S,i);
		};
	}while(i!=0);
	printf("Tumpukan yg terbentuk : \n");
	PrintStackt(S);
	printf("Tumpukan setelah dikosongkan : ");
	while(! IsEmptyStackt(S)){
    	Pop(&S,&i);
  	}
  	PrintStackt(S);
  	return 0;
}
	
