 #include "stack.c"
#include "stack.h"
#include "array.h"

Stack Hand;
Stack Nampan;
TabInt Pesanan;
void CH(Stack *Hand){
	//Membuang semua makanan di hand
	infotype bahan;
	while(! IsEmpty(*Hand)){
		Pop(Hand,&bahan);
	}
}

void TAKE(Stack *Hand,infotype bahan){
	//Mengambil objek bahan makanan
	Push(Hand,bahan);
}

void PUT(Stack *Hand,Stack *Nampan, int makanan){

	if(cek){
		CH(Hand)
		Push(Nampan, makanan);
	}
}

int CekRacikan(Stack *Hand);




